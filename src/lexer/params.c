/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   params.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 23:56:23 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 23:33:21 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/params.h"

/**
 * @brief If the current character is an unquoted '$' or '`',
 * the shell shall identify the start of any candidates
 * for parameter expansion (Parameter Expansion),
 * command substitution (Command Substitution),
 * or arithmetic expansion (Arithmetic Expansion)
 * from their introductory unquoted character sequences: 
 * '$' or "${", "$(" or '`', and "$((", respectively.
 * 
 * The shell shall read sufficient input to determine
 * the end of the unit to be expanded (as explained in the cited sections).
 * 
 * While processing the characters, if instances of expansions
 * or quoting are found nested within the substitution,
 * the shell shall recursively process them in the manner specified
 * for the construct that is found.
 * 
 * The characters found from the beginning of the substitution to its end,
 * allowing for any recursion necessary to recognize embedded constructs,
 * shall be included unmodified in the result token,
 * including any embedded or enclosing substitution operators or quotes.
 * The token shall not be delimited by the end of the substitution.
 */
int	get_param(t_shell *shell, int i)
{
	t_token	*token;
	int		x;

	x = i;
	if (!is_quote(&shell->line[i]) && shell->line[i] == '$'
		&& shell->line[i + 1] != '"' && shell->line[i + 1] != '\'')
	{
		x++;
		while (shell->line[x] && shell->line[x] != '\t'
			&& shell->line[x] != '\n' && shell->line[x] != ' '
			&& shell->line[x] != '\'' && shell->line[x] != '"'
		)
			x++;
		debug(shell, "Param found");
		token = mem_calloc(1, sizeof(t_token));
		token->value = p(ft_substr((const char *)&shell->line[i], 0, x - i));
		token->type = PARAM;
		ft_lstadd_back(&shell->tokens, p(ft_lstnew(token)));
		return (x - i);
	}
	return (0);
}
