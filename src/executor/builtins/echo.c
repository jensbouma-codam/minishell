/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/27 10:56:22 by jbouma        #+#    #+#                 */
/*   Updated: 2024/01/18 12:33:40 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor/builtins/echo.h"
#include "helper/printer.h"

static bool	print_rest(char **argv, char **envp, int i, bool new_line)
{
	char		*path;

	while (argv[i])
	{
		if (argv[i][0] == '~' && (argv[i][1] == ' ' || !argv[i][1]))
		{
			path = env_get("HOME", envp);
			ft_putstr_fd(path, 1);
			free(path);
		}
		else
			ft_putstr_fd(argv[i], 1);
		if (argv[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (new_line == TRUE)
		ft_putstr_fd("\n", 1);
	return (EXIT_SUCCESS);
}

int	b_echo(t_pipe *pipe)
{
	int			i;
	int			x;
	bool		new_line;

	i = 1;
	new_line = TRUE;
	while (pipe->argv[i] && pipe->argv[i][0] == '-')
	{
		x = 1;
		while (pipe->argv[i][x])
		{
			if (pipe->argv[i][x] != 'n')
				return (print_rest(pipe->argv, pipe->envp, i, new_line));
			x++;
		}
		new_line = FALSE;
		i++;
	}
	return (print_rest(pipe->argv, pipe->envp, i, new_line));
}
