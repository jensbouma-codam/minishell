/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 14:29:48 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 23:30:50 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

void	semi_clear(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

static void	free_t_redirect(void *ptr)
{
	t_redirect	*redirect;

	redirect = (t_redirect *)ptr;
	free(redirect->file);
	semi_clear(&redirect->tokens);
	free(redirect->tokens);
	free(redirect);
}

void	free_t_pipe(void *ptr)
{
	t_pipe	*pipe;

	pipe = (t_pipe *)ptr;
	semi_clear(&pipe->tokens);
	mem_free_array(pipe->argv);
	mem_free_array(pipe->envp);
	ft_lstclear(&pipe->redirects, free_t_redirect);
	free(pipe->redirects);
	free(pipe->tokens);
	free(pipe);
}

void	free_t_token(void *token)
{
	t_token	*tmp;

	tmp = (t_token *)token;
	free(tmp->value);
	free(tmp);
}

void	free_t_tasks(void *ptr)
{
	t_task	*task;

	task = (t_task *)ptr;
	semi_clear(&task->tokens);
	ft_lstclear(&task->pipes, free_t_pipe);
	free(task->tokens);
	free(task->pipes);
	free(task);
}
