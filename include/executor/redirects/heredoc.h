/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 11:21:25 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 10:34:20 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "libft.h"
# include "types.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

# include <curses.h>
# include <term.h>
# include "../lib/readline/readline.h"
# include "../lib/readline/history.h"

# include "executor/expander/expander.h"
# include "lexer/lexer.h"
# include "lexer/operators.h"
# include "helper/string.h"

int	heredoc(t_shell *shell, int i);

#endif