/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahornstr <ahornstr@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/12 13:22:12 by ahornstr      #+#    #+#                 */
/*   Updated: 2024/01/18 10:34:17 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar_fd('\n', STDIN_FILENO);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
	if (signum == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_handler_forked(int signum)
{
	if (signum == SIGINT)
		exit(signum + 128);
	return ;
}

void	signal_init(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

void	signal_fork_init(void)
{
	signal(SIGINT, signal_handler_forked);
	signal(SIGQUIT, signal_handler_forked);
}
