/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 23:56:23 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 23:33:14 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/quotes.h"

/**
 * @brief Return string length of quote if the current character is a quote.
 * 
 * @param str 
 * @return int 
 */
int	is_quote(const char *str)
{
	int		i;

	i = 0;
	if (str[0] == '"' || str[0] == '\'')
	{
		i++;
		while (str && str[i])
		{
			if (str[i] == str[0])
				return (i + 1);
			i++;
		}
	}
	return (0);
}

/**
 * @brief If the current character is <backslash>, single-quote,
 * or double-quote and it is not quoted, it shall affect quoting
 * for subsequent characters up to the end of the quoted text.
 * 
 * The rules for quoting are as described in Quoting.
 * 
 * During token recognition no substitutions shall be actually performed,
 * and the result token shall contain exactly the characters that appear
 * in the input (except for <newline> joining), unmodified,
 * including any embedded or enclosing quotes or substitution operators,
 * between the <quotation-mark> and the end of the quoted text.
 * 
 * The token shall not be delimited by the end of the quoted field.
 * 
 * @param i 
 * @param start 
 * @param str 
 * @param list 
 */
int	get_quote(t_shell *shell, int i)
{
	t_token			*token;
	int				len;

	len = is_quote(&shell->line[i]);
	if (len)
	{
		debug(shell, "Quote found");
		token = mem_calloc(1, sizeof(t_token));
		token->value = p(ft_substr(&shell->line[i], 0, len));
		if (token->value[0] == '\'')
			token->type = QUOTE;
		else if (token->value[0] == '"')
			token->type = DQUOTE;
		ft_lstadd_back(&shell->tokens, p(ft_lstnew(token)));
		return (len);
	}
	return (0);
}
