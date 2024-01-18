/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   blanks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 11:44:52 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 23:33:14 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/blanks.h"

/**
 * @brief  If the current character is an unquoted <blank>,
 * any token containing the previous character is delimited
 * and the current character shall be discarded.
 * 
 * @param str 
 * @return int 
 */
int	get_blank(t_shell *shell, int i)
{
	t_token	*token;
	int		x;

	x = i;
	if (shell->line[i] && (shell->line[i] == ' ' || shell->line[i] == '\t'))
	{
		while (shell->line[x]
			&& (shell->line[x] == ' '
				|| shell->line[x] == '\t'))
			x++;
		debug(shell, "Blank found");
		if (i == 0)
			return (x - i);
		token = mem_calloc(1, sizeof(t_token));
		token->value = p(ft_strdup(" "));
		token->type = BLANK;
		ft_lstadd_back(&shell->tokens, p(ft_lstnew(token)));
		return (x - i);
	}
	return (0);
}
