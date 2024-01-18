/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   words.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 23:56:23 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 23:33:14 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/words.h"

/**
 * @brief If the current character is not quoted
 * and can be used as the first character of a new operator,
 * the current token (if any) shall be delimited.
 * 
 * The current character shall be used as the beginning
 * of the next (operator) token.
 * 
 * If the previous character was part of a word,
 * the current character shall be appended to that word.
 * 
 * @param str 
 * @param list 
 * @return int 
 */
int	get_word(t_shell *shell, int i)
{
	t_token	*token;
	int		x;

	x = i;
	while (shell->line[x]
		&& shell->line[x] != '\t'
		&& shell->line[x] != '\n'
		&& shell->line[x] != ' '
		&& shell->line[x] != '\''
		&& shell->line[x] != '"'
		&& !is_operator(shell->line[x])
		&& !is_quote(&shell->line[x])
	)
		x++;
	if (x - i == 0)
		return (0);
	debug(shell, "Word found");
	token = mem_calloc(1, sizeof(t_token));
	token->value = p(ft_substr((const char *)&shell->line[i], 0, x - i));
	token->type = WORD;
	ft_lstadd_back(&shell->tokens, p(ft_lstnew(token)));
	return (x - i);
}
