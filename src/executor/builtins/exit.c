/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/27 11:04:09 by jbouma			+#    #+#                 */
/*   Updated: 2023/09/13 13:54:51 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor/builtins/exit.h"

static bool	isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/**
 * @brief Exit the shell with the given exit code.
 * 
 * @param pipe 
 * @return int 
 * @warning At 42 Machines exitcode 2 instead of 255
 */
int	exits(t_pipe *pipe)
{
	if (pipe->argc == 1)
		return (0);
	else if ((pipe->argv[1]
			&& !isnumber(pipe->argv[1])) || pipe->argv[1][0] == '\0')
	{
		ft_putstr_fd("exit: numeric argument required\n", 2);
		return (2);
	}
	else if (pipe->argc > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return (1);
	}
	if (pipe->argv[1] && !isnumber(pipe->argv[1]))
		return (2);
	if (pipe->argv[1] && isnumber(pipe->argv[1]))
		return ((unsigned char)ft_atoi(pipe->argv[1]));
	else if (pipe->argv[1] && pipe->argv[1][0] == '+'
		&& pipe->argv[2] && isnumber(pipe->argv[2]))
		return ((unsigned char)ft_atoi(pipe->argv[2]));
	else if (pipe->argv[1] && pipe->argv[1][0] == '-'
		&& pipe->argv[2] && isnumber(pipe->argv[2]))
		return ((unsigned char)ft_atoi(pipe->argv[2]) * -1);
	return (0);
}
