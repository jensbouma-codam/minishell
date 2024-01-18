/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/21 17:57:24 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 10:34:14 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <curses.h>
# include <term.h>
# include "../lib/readline/readline.h"
# include "../lib/readline/history.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

# include "libft.h"
# include "types.h"
# include "unistd.h"

void	signal_init(void);
void	signal_handler(int signum);
void	signal_handler_forked(int signum);
void	signal_fork_init(void);

#endif
