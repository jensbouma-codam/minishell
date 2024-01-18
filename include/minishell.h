/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahornstr <ahornstr@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 18:27:41 by jbouma / ah   #+#    #+#                 */
/*   Updated: 2024/01/18 09:29:30 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>

# include <curses.h>
# include <term.h>
# include "../lib/readline/readline.h"
# include "../lib/readline/history.h"

# include "types.h"

# include "cleanup.h"
# include "libft.h"
# include "signals.h"
# include "helper/colors.h"
# include "helper/debug.h"
# include "helper/mem.h"
# include "helper/string.h"
# include "lexer/lexer.h"
# include "parser/parser.h"
# include "executor/executor.h"
# include "executor/builtins/env.h"
# include "executor/builtins/unset.h"
# include "helper/debug.h"

int	clean_exit(t_shell *shell);

#endif
