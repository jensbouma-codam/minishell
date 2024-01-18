/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/16 14:20:28 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 21:42:21 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor/fork.h"

void	open_redirect(int fd, int type)
{
	if (dup2(fd, type) < 0)
		exit(error("fatal error: dup2 failed"));
}

void	execute_fork(t_shell *shell, t_list *next, t_pipe *pipe)
{
	if (pipe->redirect[0] != -1)
	{
		open_redirect(pipe->redirect[0], STDIN_FILENO);
		close(pipe->fd[0]);
	}
	else if (pipe->prev_fd[0] != -1)
	{
		open_redirect(pipe->prev_fd[0], STDIN_FILENO);
		close(pipe->fd[0]);
	}
	if (pipe->redirect[1] != -1)
		open_redirect(pipe->redirect[1], STDOUT_FILENO);
	else if (next)
		open_redirect(pipe->fd[1], STDOUT_FILENO);
	if (!buildin(shell, pipe))
		shell->exit_code = execute_external_cmd(shell, pipe);
}

void	execute_cmd(t_shell *shell, t_list *pipes, t_pipe *cmd)
{
	if (pipe(cmd->fd) != 0)
		exit(error("fatal error: pipe failed"));
	cmd->pid = fork();
	if (cmd->pid == -1)
		exit(error("fatal error: fork failed"));
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (cmd->pid == 0)
	{
		signal_fork_init();
		if (redirect(shell, cmd) == FALSE)
		{
			shell->exit_code = 1;
			close_redirect(cmd);
			exit(clean_exit(shell));
		}
		execute_fork(shell, pipes->next, cmd);
		close_redirect(cmd);
		exit(clean_exit(shell));
	}
	close(cmd->fd[1]);
	return ;
}
