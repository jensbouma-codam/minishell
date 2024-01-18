/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 13:36:45 by jbouma        #+#    #+#                 */
/*   Updated: 2024/01/18 14:37:28 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

/**
 * Adds redirects to the given task based on the tokens in the list.
 *
 * @param task   The task to add redirects to.
 * @param token  A pointer to the list of tokens.
 * @return       An integer indicating the success or failure of the operation.
 */
static int	add_redirects(t_pipe *pipe, t_list **tokens)
{
	t_redirect	*redirect;
	bool		first;

	first = TRUE;
	redirect = mem_calloc(1, sizeof(t_redirect));
	if (*tokens)
		redirect->type = ((t_token *)(*tokens)->content)->type;
	while (*tokens && (first || !int_find(((t_token *)(*tokens)->content)->type,
			(int []){LESS, DLESS, GREAT, DGREAT,
			CLOBBER, BLANK, PIPE, NEWL, 0})))
	{
		ft_lstadd_back(&redirect->tokens,
			p(ft_lstnew((t_token *)(*tokens)->content)));
		*tokens = (*tokens)->next;
		while (*tokens && (first
				&& ((t_token *)(*tokens)->content)->type == BLANK))
			*tokens = (*tokens)->next;
		first = FALSE;
	}
	redirect->index = ft_lstsize(pipe->redirects);
	ft_lstadd_back(&pipe->redirects, p(ft_lstnew(redirect)));
	while (*tokens && ((t_token *)(*tokens)->content)->type == BLANK)
		*tokens = (*tokens)->next;
	return (TRUE);
}

static	void	skip_blank_newl(t_list **tokens)
{
	while (*tokens
		&& (((t_token *)(*tokens)->content)->type == BLANK
		|| ((t_token *)(*tokens)->content)->type == NEWL))
		*tokens = (*tokens)->next;
}

static	void	parse_redirects(t_list **tokens, t_pipe *pipe)
{
	if (*tokens
		&& int_find(((t_token *)(*tokens)->content)->type,
		(int []){LESS, DLESS, GREAT, DGREAT, CLOBBER, 0}))
	{
		add_redirects(pipe, tokens);
		parse_redirects(tokens, pipe);
	}
}

/**
 * Splits the tokens of a task into pipes and redirects.
 *
 * @param task The task whose tokens need to be split.
 */
static void	parse_task(t_task *task)
{
	t_list		*tokens;
	t_pipe		*pipe;

	tokens = task->tokens;
	pipe = mem_calloc(1, sizeof(t_pipe));
	while (tokens)
	{
		parse_redirects(&tokens, pipe);
		if ((int_find(((t_token *)tokens->content)->type,
					(int []){PIPE, EXPORT, OR_IF, AND_IF, NEWL, 0}) || !tokens))
		{
			ft_lstadd_back(&task->pipes, p(ft_lstnew(pipe)));
			pipe->index = ft_lstsize(task->pipes);
			if (tokens->next)
				pipe = mem_calloc(1, sizeof(t_pipe));
			tokens = tokens->next;
			skip_blank_newl(&tokens);
			continue ;
		}
		else
			ft_lstadd_back(&pipe->tokens, p(ft_lstnew(tokens->content)));
		tokens = tokens->next;
	}
}

/**
 * Splits the tokens into tasks and pipes.
 * A task is split by AND_IF, OR_IF, SEMICOLON & NEWLINE.
 * 
 * @param token 
 * @param shell 
 * @return true 
 * @return false 
 */
bool	parser(t_shell *shell)
{
	t_task	*task;
	t_list	*token;

	token = shell->tokens;
	task = mem_calloc(1, sizeof(t_task));
	task->index = ft_lstsize(shell->tasks);
	ft_lstadd_back(&shell->tasks, p(ft_lstnew(task)));
	while (token)
	{
		ft_lstadd_back(&task->tokens, p(ft_lstnew(token->content)));
		if (int_find(((t_token *)token->content)->type,
				(int []){AND_IF, OR_IF, SEMICOLON, NEWL, 0}))
		{
			expander(task, shell);
			parse_task(task);
			if (!token->next)
				break ;
			task = mem_calloc(1, sizeof(t_task));
			task->index = ft_lstsize(shell->tasks);
			ft_lstadd_back(&shell->tasks, p(ft_lstnew(task)));
		}
		token = token->next;
	}
	return (TRUE);
}
