/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 12:45:06 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 13:06:31 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/lexer.h"
#include "executor/redirects/heredoc.h"

static bool	is_closed_quote(t_shell *shell, int i)
{
	if (shell->line[i] != '\'' && shell->line[i] != '"')
		return (TRUE);
	if (is_quote(&shell->line[i]))
		return (TRUE);
	return (FALSE);
}

static void	add_newline(t_shell *shell)
{
	t_token	*token;

	token = mem_calloc(1, sizeof(t_token));
	token->type = NEWL;
	token->value = p(ft_strdup("\n"));
	ft_lstadd_back(&shell->tokens, p(ft_lstnew(token)));
}

static int	skip_single_dolar(t_shell *shell, int i)
{
	if (shell->line[i] == '$'
		&& (shell->line[i + 1] == '\''
			|| shell->line[i + 1] == '\"'))
		return (1);
	return (0);
}

static int	get_newline(t_shell *shell, int i)
{
	if (shell->line[i] == '\n')
	{
		debug(shell, "Newline found");
		add_newline(shell);
		return (1);
	}
	return (0);
}

bool	lexer(t_shell *shell)
{
	int		i;
	int		x;

	i = 0;
	while (shell->line[i])
	{
		x = i;
		i += heredoc(shell, i);
		i += get_double_operator(shell, i);
		i += get_single_operator(shell, i);
		if (!is_closed_quote(shell, i))
			return (printf("Unclosed quote near %s\n", &shell->line[i]), FALSE);
		i += get_quote(shell, i);
		i += get_param(shell, i);
		i += skip_single_dolar(shell, i);
		i += get_newline(shell, i);
		i += get_word(shell, i);
		i += get_comment(shell, i);
		i += get_blank(shell, i);
		if (x == i)
			return (printf("Syntax error near %s\n", &shell->line[i]), FALSE);
	}
	add_newline(shell);
	return (TRUE);
}
