# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jbouma <jbouma@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/10 14:09:40 by jbouma        #+#    #+#                  #
#    Updated: 2024/01/18 17:34:19 by jensbouma     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Program Name(s)
NAME		:= bin/minishell

# Libraries
LIBDIR		:= lib
LIBS		:= readline libft
LIBS_INC	=  -I lib/readline -I lib/libft/include
LIBS_E 		:= -lncurses
#  -ltermcap -lreadline

# Sources
FILES		:= 	minishell.c						\
				cleanup.c						\
				signals.c						\
				helper/mem.c					\
				helper/error.c					\
				helper/debug.c					\
				helper/string.c					\
				helper/int.c					\
				helper/printer.c				\
				helper/printer2.c				\
				helper/array.c					\
				helper/file.c					\
				lexer/lexer.c					\
				lexer/quotes.c					\
				lexer/operators.c				\
				lexer/params.c					\
				lexer/export.c					\
				lexer/words.c					\
				lexer/comments.c				\
				lexer/blanks.c					\
				parser/parser.c					\
				parser/validate.c				\
				executor/executor.c				\
				executor/fork.c					\
				executor/expander/expander.c	\
				executor/builtins/builtins.c	\
				executor/builtins/echo.c		\
				executor/builtins/cd.c			\
				executor/builtins/env.c			\
				executor/builtins/pwd.c			\
				executor/builtins/export.c		\
				executor/builtins/exit.c		\
				executor/builtins/unset.c		\
				executor/redirects/redirects.c	\
				executor/redirects/heredoc.c	\
				executor/external.c				\

# Set directories
BUILDDIR	:= build
SRCDIR		:= src
INC 		:= include

# Compiler Settings
CC 			:= gcc
CFLAGS		+= -Werror -Wall -Wextra
# CFLAGS		+= -O3
CFLAGS		+= -DREADLINE_LIBRARY

# Dynamic shizzle
SOURCES		= ${addprefix $(SRCDIR)/, $(FILES)}
LIBS_A		= $(addsuffix /*.a, $(addprefix $(LIBDIR)/, $(LIBS)))
OBJECTS		= $(SOURCES:%.c=$(BUILDDIR)/%.o)

# Objects and dependencies

# Colors
ifneq (,$(findstring xterm,${TERM}))
	BLACK		:= $(shell tput -Txterm setaf 0)
	RED			:= $(shell tput -Txterm setaf 1)
	GREEN		:= $(shell tput -Txterm setaf 2)
	YELLOW		:= $(shell tput -Txterm setaf 3)
	LIGHTPURPLE	:= $(shell tput -Txterm setaf 4)
	PURPLE		:= $(shell tput -Txterm setaf 5)
	BLUE		:= $(shell tput -Txterm setaf 6)
	WHITE		:= $(shell tput -Txterm setaf 7)
	RESET		:= $(shell tput -Txterm sgr0)
endif

P				:= printf "%-25.25s%s\n"
BUILD_CHECK		= && $(P) "Build${GREEN}" "$@$(RESET)" || $(P) "Build${RED}" "$@$(RESET)"
BUILD_FATAL		= && $(P) "Build${GREEN}" "$@$(RESET)" || ($(P) "Build${RED}" "$@$(RESET)" && exit 1)
GIT_FATAL		= && $(P) "Git pull${GREEN}" "$@$(RESET)" || ($(P) "Git pull failed${RED}" "$@$(RESET)" && exit 1)
EXEC_FATAL		= && $(P) "Executable${GREEN}" "$@$(RESET)" || ($(P) "Executable${RED}" "$@$(RESET)" && exit 1)
FINAL			= && $(P) "🙏$(PURPLE) All Done" "$(RESET)" || $(P) "🤬 $(RED)Norm Error" "$(RESET)"

# Rules
all: $(INIT) $(NAME)
	@norminette -R CheckForbiddenSourceHeader $(SOURCES) $(INC) 2>&1 > /dev/null $(FINAL)

$(NAME): $(LIBS_A) $(OBJECTS)
	@mkdir -p $(dir $@)
	@$(P) "Flags $(YELLOW)" "$(CFLAGS) $(RESET)"
# @$(CC) $(CFLAGS) $(LIBS_E) -I$(INC) $(LIBS_INC) $(OBJECTS) $(LIBS_A) -o $(NAME) $(EXEC_FATAL)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBS_A) $(LIBS_E) -I$(INC) $(LIBS_INC) -o $(NAME) $(EXEC_FATAL)

$(INIT):
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o:%.c
	@mkdir -p $(dir $@)
	@norminette -R CheckForbiddenSourceHeader $< > /dev/null $(BUILD_CHECK)
	@$(CC) $(CFLAGS) -I$(INC) $(LIBS_INC) -c $< -o $@

$(LIBS_A): $(LIBS)

$(LIBS):
	@if [ ! -f "$(LIBDIR)/$@/Makefile" ] && [ ! -f "$(LIBDIR)/$@/configure" ]; then 									\
		git submodule update --init -- ./lib/$@ &> /dev/null $(GIT_FATAL); fi

	@if [ $@ = "readline" ] && [ ! -f $(LIBDIR)/$@/Makefile ]; then \
		cd $(LIBDIR)/$@ && ./configure > /dev/null; fi

	@if [ $@ = "readline" ] && [ -f $(LIBDIR)/$@/Makefile ] && [ ! -f $(LIBDIR)/$@/libreadline.a ]; then 				\
		cd $(LIBDIR)/$@ && $(MAKE) static > /dev/null $(BUILD_FATAL); fi

	@if [ $@ = "libft" ] && [ ! -f $(LIBDIR)/$@/libft.a ]; then $(MAKE) -C $(LIBDIR)/$@ > /dev/null $(BUILD_FATAL); fi

clean:
	@rm -rf $(BUILDDIR)
	@git submodule foreach --recursive git clean -xfd 2>&1 > /dev/null
	@rm -rf bin/minishell_tester

fclean: clean
	@rm -rf $(dir $(NAME))

re: fclean all

debug: CFLAGS += -D DEBUG=1 -g -fsanitize=address
debug: all
	@printf "$(RED)Compiled in debug / fsanitize=address mode!!!$(RESET)\n\n"

leaks: CFLAGS += -D DEBUG=2 -g
leaks: all
	@printf "$(RED)Compiled in debug / leaks mode!!!$(RESET)\n\n"

grind: CFLAGS += -D DEBUG=1 -g
grind: all
	@printf "$(RED)Compiled in debug / grind mode!!!$(RESET)\n\n"
	@valgrind --leak-check=full --show-leak-kinds=all --suppressions=supp.supp --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME)

test: all
	@if [ ! -d "./bin/minishell_tester" ]; then 																			\
		git clone https://github.com/LucasKuhn/minishell_tester.git bin/minishell_tester > /dev/null $(GIT_FATAL)		\
	fi
	@cd bin/minishell_tester && ./tester

.PHONY: CFLAGS all clean fclean re
