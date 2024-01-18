/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   comments.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 11:44:43 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 00:09:00 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/comments.h"

/**
 * @brief If the current character is a '#', it and all subsequent characters
 * up to, but excluding, the next <newline> shall be discarded as a comment.
 * The <newline> that ends the line is not considered part of the comment.
 * 
 * @param str 
 * @param list 
 * @return int 
 */
int	get_comment(t_shell *shell, int i)
{
	t_token	*t;
	int		x;

	x = i;
	if (shell->line[i] == ' ' && shell->line[i + 1] == '#')
	{
		x++;
		while (shell->line[x] && shell->line[x] != '\0')
			x++;
		debug(shell, "Comment found");
		t = mem_calloc(1, sizeof(t_token));
		t->value = p(ft_substr((const char *)&shell->line[i + 1], 0, x - i));
		t->type = COMMENT;
		ft_lstadd_back(&shell->tokens, p(ft_lstnew(t)));
		return (x - i + 1);
	}
	return (0);
}
