/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 19:59:54 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 14:10:54 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser/validate.h"
#include "helper/printer.h"

/**
 * Validates if the tokens after a pipe symbol are valid.
 *
 * @param tokens A linked list of tokens.
 * @return true if the tokens are valid, false otherwise.
 */
static bool	valid_after_pipe(t_list *tokens)
{
	int		type;
	int		next;

	next = NONE;
	type = ((t_token *)tokens->content)->type;
	if (tokens->next)
		next = ((t_token *)tokens->next->content)->type;
	if (type == PIPE
		&& next && !int_find(next, (int [])
			{WORD, PARAM, GREAT, DGREAT, LESS, DLESS, BLANK, 0}))
	{
		ft_putstr_fd("error: syntax error near unexpected token `", 2);
		ft_putstr_fd(((t_token *)tokens->content)->value, 2);
		ft_putendl_fd("'", 2);
		return (FALSE);
	}
	return (TRUE);
}

/**
 * Validates if the tokens after a redirect are valid.
 *
 * @param tokens The list of tokens to validate.
 * @return true if the tokens are valid, false otherwise.
 */
static bool	valid_after_redirect(t_list *tokens)
{
	int	next;

	next = NONE;
	if (tokens->next)
		next = ((t_token *)tokens->next->content)->type;
	if (int_find(((t_token *)tokens->content)->type,
			(int []){LESS, DLESS, GREAT, DGREAT, 0})
		&& tokens->next && !int_find(next,
			(int []){WORD, PARAM, DQUOTE, QUOTE, PIPE, BLANK, 0}))
	{
		while (tokens->next && next == BLANK)
		{
			tokens = tokens->next;
			next = ((t_token *)tokens->next->content)->type;
		}
		ft_putstr_fd("error: syntax error near unexpected token `", 2);
		if (tokens->next && next != NEWL)
			ft_putstr_fd(((t_token *)tokens->next->content)->value, 2);
		else
			ft_putstr_fd("newline", 2);
		ft_putendl_fd("'", 2);
		return (FALSE);
	}
	return (TRUE);
}

/**
 * Checks if there are no double redirects in the given list of tokens.
 *
 * @param tokens The list of tokens to validate.
 * @return true if there are no double redirects, false otherwise.
 */
static bool	no_double_redirect(t_list *tokens)
{
	int		type;
	int		next;

	next = NONE;
	type = ((t_token *)tokens->content)->type;
	if (tokens->next)
		next = ((t_token *)tokens->next->content)->type;
	if (int_find(type, (int []){LESS, DLESS, GREAT, DGREAT, 0})
		&& next && int_find(next, (int [])
			{LESS, DLESS, GREAT, DGREAT, PIPE, 0}))
	{
		ft_putstr_fd("error: syntax error near unexpected token `", 2);
		ft_putstr_fd(((t_token *)tokens->next->content)->value, 2);
		ft_putendl_fd("'", 2);
		return (FALSE);
	}
	return (TRUE);
}

/**
 * Validates if the last token in the given list is not a special token.
 *
 * @param tokens The list of tokens to validate.
 * @param first  A boolean indicating if it is the first token in the list.
 * @return       True if the last token is not a special token, false otherwise.
 */
static bool	last_not_special(t_list *tokens, bool first)
{
	int		type;

	type = ((t_token *)tokens->content)->type;
	if (!int_find(type, (int []){LESS, DLESS, GREAT, DGREAT,
			WORD, PARAM, QUOTE, CLOBBER, DQUOTE, NEWL, 0})
			&& (!tokens->next || first))
	{
		ft_putstr_fd("error: syntax error near unexpected token `", 2);
		ft_putstr_fd(((t_token *)tokens->content)->value, 2);
		ft_putendl_fd("'", 2);
		return (FALSE);
	}
	return (TRUE);
}

/**
 * Checks if the tokens in the given linked list are valid.
 * A token is considered valid if it is not one of the following types:
 * AND_IF, OR_IF, SEMICOLON, PIPE, and it is not the last token in the list.
 * If an invalid token is found, an error message is printed to stderr.
 *
 * @param tokens The linked list of tokens to be checked.
 * @return TRUE if all tokens are valid, FALSE otherwise.
 */
bool	validate(t_list *tokens)
{
	bool	first;

	first = TRUE;
	while (tokens)
	{
		if (first && ((t_token *)tokens->content)->type == COMMENT)
			return (FALSE);
		if (!no_double_redirect(tokens)
			|| !valid_after_redirect(tokens)
			|| !valid_after_pipe(tokens)
			|| !last_not_special(tokens, first))
			return (FALSE);
		first = FALSE;
		tokens = tokens->next;
		if (tokens && ((t_token *)tokens->content)->type == NEWL)
			tokens = tokens->next;
	}
	return (TRUE);
}
