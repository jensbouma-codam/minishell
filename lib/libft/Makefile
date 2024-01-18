# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jbouma <jbouma@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/10 14:09:40 by jbouma        #+#    #+#                  #
#    Updated: 2023/05/16 15:53:26 by jbouma        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Program Name(s)
NAME 		=	libft.a

# Compiler Settings
CC 			:= gcc
CFLAGS 		:= -Wall -Wextra -Werror

# Headers
INC			=	-I include

# Set source and build directories
SRCDIR		= src
BUILDDIR	= build/

# FILES		= $(notdir $(shell find $(SRCDIR) -type f -name *.c))
FILES		=	ft_atoi.c				\
				ft_bzero.c				\
				ft_calloc.c				\
				ft_isalnum.c			\
				ft_isalpha.c			\
				ft_isascii.c			\
				ft_isdigit.c			\
				ft_isprint.c			\
				ft_itoa.c				\
				ft_lstadd_back_bonus.c	\
				ft_lstadd_front_bonus.c	\
				ft_lstclear_bonus.c		\
				ft_lstdelone_bonus.c	\
				ft_lstiter_bonus.c		\
				ft_lstlast_bonus.c		\
				ft_lstmap_bonus.c		\
				ft_lstnew_bonus.c		\
				ft_lstsize_bonus.c		\
				ft_memchr.c				\
				ft_memcmp.c				\
				ft_memcpy.c				\
				ft_memmove.c			\
				ft_memset.c				\
				ft_printf.c				\
				ft_putchar_fd.c			\
				ft_putendl_fd.c			\
				ft_puthex_fd.c			\
				ft_putnbr_fd.c			\
				ft_putpointer_fd.c		\
				ft_putstr_fd.c			\
				ft_putunsigned_fd.c		\
				ft_split.c				\
				ft_strchr.c				\
				ft_strdup.c				\
				ft_striteri.c			\
				ft_strjoin.c			\
				ft_strlcat.c			\
				ft_strlcpy.c			\
				ft_strlen.c				\
				ft_strmapi.c			\
				ft_strcmp.c				\
				ft_strncmp.c			\
				ft_strnstr.c			\
				ft_strrchr.c			\
				ft_strstr.c				\
				ft_strtrim.c			\
				ft_substr.c				\
				ft_tolower.c			\
				ft_toupper.c			\
				get_next_line_utils.c	\
				get_next_line.c			\


SOURCES		=	${addprefix $(SRCDIR)/, $(FILES)}


OBJECTS		= $(SOURCES:%.c=$(BUILDDIR)%.o)

all: $(NAME)
	@printf "%-25.25s%s\n" "Libary" "$(NAME)"

$(NAME): $(OBJECTS)
	@ar -rcs $(NAME) $^

$(BUILDDIR)%.o:%.c
	@mkdir -p build
	@printf "%-25.25s%s\n" "Build" "$(notdir $<)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

clean:
	@rm -rf build

fclean: clean
	@rm -rf *.a

re: fclean all

.PHONY: all clean fclean re