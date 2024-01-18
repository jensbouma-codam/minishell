/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 14:25:16 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 14:36:37 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor/executor.h"
#include "helper/printer.h"

static char	**token_to_arr(t_list *tokens)
{
	t_token	*token;
	char	**arr;
	int		i;

	arr = mem_calloc(sizeof(char *), (ft_lstsize(tokens) + 1));
	i = 0;
	while (tokens)
	{
		token = tokens->content;
		if (!(token->type == PARAM && token->value[0] == '\0')
			&& !int_find(token->type, (int []){BLANK, COMMENT, 0}))
		{
			if (arr[i] == NULL)
				arr[i] = p(ft_strdup(token->value));
			else
				arr[i] = free_join(arr[i], p(ft_strdup(token->value)));
			tokens = tokens->next;
			continue ;
		}
		if (arr[i] != NULL)
			i++;
		tokens = tokens->next;
	}
	return (arr);
}

void	execute_pipeline(t_shell *shell, t_list	*pipes)
{
	t_pipe	*cmd;

	while (pipes)
	{
		cmd = pipes->content;
		cmd->envp = mem_cpy_array(shell->envp);
		cmd->argv = token_to_arr(cmd->tokens);
		cmd->argc = array_len(cmd->argv);
		cmd->redirect[0] = -1;
		cmd->redirect[1] = -1;
		if (ft_lstsize(cmd->redirects) == 0 && ft_lstsize(pipes) == 1
			&& buildin(shell, cmd))
		{
			mem_free_array(shell->envp);
			shell->envp = mem_cpy_array(cmd->envp);
			return ;
		}
		execute_cmd(shell, pipes, cmd);
		pipes = pipes->next;
		if (pipes)
			((t_pipe *)pipes->content)->prev_fd[0] = cmd->fd[0];
	}
}

void	wait_pipes(t_shell *shell, t_list *pipes)
{
	t_pipe	*cmd;
	t_list	*last;

	(void)shell;
	last = ft_lstlast(pipes);
	cmd = last->content;
	if (cmd->pid != 0)
	{
		waitpid(cmd->pid, &cmd->status, 0);
		if (WIFEXITED(cmd->status))
			shell->exit_code = WEXITSTATUS(cmd->status);
		else if (WIFSIGNALED(cmd->status))
			shell->exit_code = WTERMSIG(cmd->status) + 128;
		while (pipes->next)
		{
			cmd = pipes->content;
			close(cmd->fd[0]);
			pipes = pipes->next;
		}
	}
}

bool	executor(t_shell *shell)
{
	t_list	*tasks;
	t_task	*task;

	tasks = shell->tasks;
	while (tasks)
	{
		task = tasks->content;
		execute_pipeline(shell, task->pipes);
		wait_pipes(shell, task->pipes);
		tasks = tasks->next;
	}
	return (TRUE);
}
