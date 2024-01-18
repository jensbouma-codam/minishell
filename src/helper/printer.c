/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 15:51:17 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 19:40:22 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper/printer.h"

void	print_list(t_list *list, void (*print_func)(void *, int), int indent)
{
	while (list != NULL)
	{
		print_func(list->content, indent);
		list = list->next;
	}
}

void	print_token(t_token *token, int indent)
{
	static const char	*token_type_names[] = {
		"EMPTY", "WORD", "NAME", "AND_IF", "OR_IF", "DSEMI", "DLESS",
		"DGREAT", "LESSAND", "GREATAND", "LESSGREAT", "PARAMETER", "PIPE",
		"SEMICOLON", "COMMENT", "LESS", "GREAT", "BLANK", "AND", "CLOBBER",
		"QUOTE", "DQUOTE", "EXPORT", "COMMAND", "ARGUMENT", "NEWLINE"
	};
	char				*token_type;

	token_type = ("UNKNOWN");
	if (token->type >= 0 && token->type <= 25)
		token_type = ((char *)token_type_names[token->type]);
	if (token->type == NEWL)
		printf("%*sToken: { value: %s%s%s, type: %s%s%s }\n",
			indent, "", YELLOW, "newline", RESET, BLUE,
			token_type, RESET);
	else
		printf("%*sToken: { value: %s%s%s, type: %s%s%s }\n",
			indent, "", YELLOW, token->value, RESET, BLUE,
			token_type, RESET);
}

void	print_pipe(t_pipe *pipe, int indent)
{
	printf("%*sPipe: { index: %s%d%s, pid: %s%d%s, \
		argc: %s%d%s }\n",
		indent, "",
		CYAN, pipe->index, RESET,
		GREEN, pipe->pid, RESET,
		YELLOW, pipe->argc, RESET);
	printf("%*sTokens:\n", indent + 2, "");
	print_list(pipe->tokens, (void (*)(void *, int))print_token, indent + 4);
	printf("%*sRedirects:\n", indent + 2, "");
	print_list(pipe->redirects,
		(void (*)(void *, int))print_redirect, indent + 4);
}

void	print_task(t_task *task, int indent)
{
	printf("%*sTask: { index: %s%d%s }\n",
		indent, "",
		CYAN, task->index, RESET);
	printf("%*sTokens:\n", indent + 2, "");
	print_list(task->tokens, (void (*)(void *, int))print_token, indent + 4);
	printf("%*sPipes:\n", indent + 2, "");
	print_list(task->pipes, (void (*)(void *, int))print_pipe, indent + 4);
}

int	print_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (ft_putstr_fd(arr[i], 1) == -1 || ft_putstr_fd("\n", 1) == -1)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
