/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 13:02:19 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 10:03:36 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor/redirects/redirects.h"

bool	close_redirect(t_pipe *pipe)
{
	if (pipe->redirect[1] != -1)
	{
		close(pipe->redirect[1]);
		pipe->redirect[1] = -1;
	}
	if (pipe->redirect[0] != -1)
	{
		close(pipe->redirect[0]);
		pipe->redirect[0] = -1;
	}
	return (TRUE);
}

static bool	in_redirect(char *file, t_pipe *pipe)
{
	if (pipe->redirect[0] != -1)
		close(pipe->redirect[0]);
	pipe->redirect[0] = open(file, O_RDONLY);
	if (pipe->redirect[0] == -1)
	{
		ft_putstr_fd("in_redirect: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		close(pipe->redirect[0]);
		pipe->redirect[0] = -1;
		return (FALSE);
	}
	return (TRUE);
}

static bool	out_redirect(int type, char *file, t_pipe *pipe)
{
	if (pipe->redirect[1] != -1)
		close(pipe->redirect[1]);
	if (type == GREAT || type == CLOBBER)
		pipe->redirect[1] = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == DGREAT)
		pipe->redirect[1] = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (pipe->redirect[1] == -1)
	{
		ft_putstr_fd("out_redirect: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		close(pipe->redirect[1]);
		pipe->redirect[1] = -1;
		return (FALSE);
	}
	return (TRUE);
}

static void	upgrade_redirect(t_redirect *redirect)
{
	t_list	*tokens;

	tokens = redirect->tokens->next;
	while (tokens)
	{
		if (!redirect->file)
			redirect->file = p(ft_strdup(((t_token *)tokens->content)->value));
		else
			redirect->file = free_join(redirect->file,
					p(ft_strdup(((t_token *)tokens->content)->value)));
		tokens = tokens->next;
	}
}

bool	redirect(t_shell *shell, t_pipe *pipe)
{
	t_list	*redirects;
	char	*file;
	int		type;

	pipe->redirect[0] = -1;
	pipe->redirect[1] = -1;
	redirects = pipe->redirects;
	while (redirects)
	{
		upgrade_redirect(redirects->content);
		type = ((t_redirect *)(redirects)->content)->type;
		((t_redirect *)(redirects)->content)->type = NONE;
		file = ((t_redirect *)(redirects)->content)->file;
		if (!file || !valid_file(shell, file))
			return (FALSE);
		if (type == LESS && !in_redirect(file, pipe))
			return (FALSE);
		else if ((type == GREAT || type == DGREAT || type == CLOBBER)
			&& !out_redirect(type, file, pipe))
			return (FALSE);
		redirects = redirects->next;
	}
	return (TRUE);
}
