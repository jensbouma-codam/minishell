/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printer2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 15:51:17 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 16:11:10 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper/printer.h"

void	print_redirect(t_redirect *redirect, int indent)
{
	printf("%*sRedirect: { index: %s%d%s, type: %s%d%s, \
		file: %s%s%s }\n",
		indent, "",
		CYAN, redirect->index, RESET,
		GREEN, redirect->type, RESET,
		YELLOW, redirect->file, RESET);
	printf("%*sTokens:\n", indent + 2, "");
	print_list(redirect->tokens,
		(void (*)(void *, int))print_token, indent + 4);
}

int	print_array_export(char **arr)
{
	int		i;
	char	**split;

	i = 0;
	while (arr[i] != NULL)
	{
		split = p(ft_split(arr[i], '='));
		ft_putstr_fd("declare -x ", 1);
		if (ft_putstr_fd(split[0], 1) == -1)
			return (EXIT_FAILURE);
		if (split[1] != NULL)
		{
			ft_putstr_fd("=\"", 1);
			if (ft_putstr_fd(split[1], 1) == -1)
				return (EXIT_FAILURE);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		mem_free_array(split);
		i++;
	}
	return (EXIT_SUCCESS);
}
