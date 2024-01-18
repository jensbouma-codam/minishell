/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 13:21:46 by jbouma        #+#    #+#                 */
/*   Updated: 2024/01/18 17:57:07 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor/expander/expander.h"
#include "helper/debug.h"

// @jensbouma protect libft functions!!!
static char	*dollar_something(char *str, int i, char *fill)
{
	char	*tmp;
	char	*tmp2;

	tmp = p(ft_substr(str, i + 2, ft_strlen(str) - i - 2));
	tmp2 = free_join(ft_substr(str, 0, i), fill);
	free(str);
	return (free_join(tmp2, tmp));
}

static char	*dollar(char *str, int i, t_shell *shell)
{
	char	*tmp;
	char	*tmp2;
	char	*var;
	int		x;
	int		y;

	x = i;
	while (str[x] && str[x] != ' ' && str[x] != '$' && str[x] != '=')
		x++;
	y = x + 1;
	while (str[y] && str[y] != ' ' && str[y] != '$' && str[y] != '='
		&& str[y] != '\'' && str[y] != '\"' && str[y] != '/' && str[y] != '.')
		y++;
	tmp = p(ft_substr(str, y, ft_strlen(str) - y));
	var = p(ft_substr(str, i + 1, y - x - 1));
	tmp2 = free_join(ft_substr(str, 0, i), env_get(var, shell->envp));
	free(var);
	free(str);
	return (free_join(tmp2, tmp));
}

char	*expand_string(char *str, t_shell *shell)
{
	int		i;

	i = 0;
	if (str[0] == '$' && str[1] == '\0')
	{
		free(str);
		return (p(ft_strdup("$")));
	}
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
			str = dollar_something(str, i, p(ft_itoa(shell->exit_code)));
		else if (str[i] == '$' && str[i + 1] == '$')
			str = dollar_something(str, i, p(ft_itoa(getpid())));
		else if (str[i] == '$' && str[i + 1] != '\0'
			&& str[i + 1] != ' ' && str[i + 1] != '/')
			str = dollar(str, i, shell);
		else if (++i)
			continue ;
		i = 0;
	}
	return (str);
}

void	expander(t_task *task, t_shell *shell)
{
	t_list	*tokens;
	t_token	*token;
	t_list	*insert;
	char	*str;

	tokens = task->tokens;
	insert = NULL;
	while (tokens)
	{
		token = tokens->content;
		if (token->type == QUOTE || token->type == DQUOTE)
			str = p(ft_substr(token->value, 1, ft_strlen(token->value) - 2));
		else
			str = p(ft_strdup(token->value));
		free(token->value);
		if (token->type != QUOTE)
			token->value = expand_string(str, shell);
		else
			token->value = str;
		tokens = tokens->next;
	}
	if (insert != NULL)
		task->tokens = insert;
}
