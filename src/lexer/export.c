/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 14:02:10 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 23:33:14 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/export.h"

static	int	replace_token(t_shell *shell, int i, int x, t_token_type type)
{
	t_token	*token;

	token = mem_calloc(1, sizeof(t_token));
	token->type = type;
	token->value = p(ft_substr(shell->line, i, x));
	ft_lstadd_back(&shell->tokens, p(ft_lstnew(token)));
	return (i + x);
}

int	get_exports(t_shell *shell, int i)
{
	int		x;
	t_token	*token;

	token = mem_calloc(1, sizeof(t_token));
	x = 0;
	if (ft_strchr(shell->line + i, '=') == NULL)
		return (i);
	while (shell->line[i] == ' ')
		i++;
	while (shell->line[x + i] != '\0' && shell->line[x + i] != ' '
		&& shell->line[x + i] != '\'' && shell->line[x + i] != '"'
		&& shell->line[x + i] != '#' && !is_operator(shell->line[x + i])
		&& !is_quote(&shell->line[x + i])
	)
		x++;
	token->type = WORD;
	token->value = p(ft_strdup("export"));
	ft_lstadd_back(&shell->tokens, p(ft_lstnew(token)));
	token = mem_calloc(1, sizeof(t_token));
	token->type = BLANK;
	token->value = p(ft_strdup(" "));
	ft_lstadd_back(&shell->tokens, p(ft_lstnew(token)));
	return (replace_token(shell, i, x, WORD));
}
