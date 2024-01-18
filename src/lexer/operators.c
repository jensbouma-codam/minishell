/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operators.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 13:18:28 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 23:33:14 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/operators.h"

t_token_type	get_double_operator_meta(char *str)
{
	if (ft_strncmp(str, "<<", 2) == 0)
		return (DLESS);
	if (ft_strncmp(str, ">>", 2) == 0)
		return (DGREAT);
	if (ft_strncmp(str, "&&", 2) == 0)
		return (AND_IF);
	if (ft_strncmp(str, "||", 2) == 0)
		return (OR_IF);
	if (ft_strncmp(str, "<&", 2) == 0)
		return (LESSAND);
	if (ft_strncmp(str, ">&", 2) == 0)
		return (GREATAND);
	if (ft_strncmp(str, "<>", 2) == 0)
		return (LESSGREAT);
	if (ft_strncmp(str, ">|", 2) == 0)
		return (CLOBBER);
	return (WORD);
}

static t_token_type	get_single_operator_meta(char *str)
{
	if (ft_strncmp(str, "<", 1) == 0)
		return (LESS);
	if (ft_strncmp(str, ">", 1) == 0)
		return (GREAT);
	if (ft_strncmp(str, "|", 1) == 0)
		return (PIPE);
	if (ft_strncmp(str, "&", 1) == 0)
		return (AND);
	return (WORD);
}

int	is_operator(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == '&')
		return (TRUE);
	return (FALSE);
}

/**
 * @brief If the previous character was used as part of an operator
 * and the current character is not quoted
 * and can be used with the previous characters to form an operator,
 * it shall be used as part of that (operator) token.
 * 
 * @param i 
 * @param start 
 * @param str 
 * @param list 
 * @return true 
 * @return false 
 */
int	get_double_operator(t_shell *shell, int i)
{
	t_token			*token;

	if (!is_quote(&shell->line[i])
		&& is_operator(shell->line[i])
		&& is_operator(shell->line[i + 1])
		&& get_double_operator_meta(&shell->line[i]) != WORD
		// && shell->line[i] == shell->line[i + 1]
	)
	{
		debug(shell, "Double operator found");
		token = mem_calloc(1, sizeof(t_token));
		if (!token)
			return (-1);
		token->value = p(ft_substr(&shell->line[i], 0, 2));
		token->type = get_double_operator_meta(token->value);
		ft_lstadd_back(&shell->tokens, p(ft_lstnew(token)));
		return (2);
	}
	return (0);
}

/**
 * @brief If the previous character was used as part of an operator
 * and the current character cannot be used
 * with the previous characters to form an operator, 
 * the operator containing the previous character shall be delimited.
 * 
 * @param i 
 * @param start 
 * @param str 
 * @param list 
 * @return true 
 * @return false 
 */
int	get_single_operator(t_shell *shell, int i)
{
	t_token			*token;

	if (!is_quote(&shell->line[i])
		&& is_operator(shell->line[i])
		&& (shell->line[i] != shell->line[i + 1])
	)
	{
		debug(shell, "Single operator found");
		token = mem_calloc(1, sizeof(t_token));
		if (!token)
			return (-1);
		token->value = p(ft_substr(&shell->line[i], 0, 1));
		token->type = get_single_operator_meta(token->value);
		ft_lstadd_back(&shell->tokens, p(ft_lstnew(token)));
		return (1);
	}
	return (0);
}
