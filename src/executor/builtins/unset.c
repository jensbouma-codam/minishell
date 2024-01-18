/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahornstr <ahornstr@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/27 12:21:00 by ahornstr      #+#    #+#                 */
/*   Updated: 2024/01/17 23:49:33 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor/builtins/unset.h"
#include "helper/printer.h"

static int	find_line(char *argv, char **s_envp)
{
	int		i;
	size_t	j;

	j = 0;
	i = 0;
	while (s_envp[i])
	{
		j = 0;
		while (s_envp[i][j] != '=' && s_envp[i][j] != '\0')
			j++;
		if (!ft_strncmp(argv, s_envp[i], j) && j == ft_strlen(argv))
			return (i);
		i++;
	}
	return (-1);
}

int	unset(t_pipe *cmd)
{
	int		i;
	int		line;
	char	**old;

	i = 1;
	while (i < cmd->argc)
	{
		line = find_line(cmd->argv[i], cmd->envp);
		if (line >= 0)
		{
			old = cmd->envp;
			cmd->envp = array_remove_line(cmd->envp, line);
			mem_free_array(old);
		}
		i++;
	}
	return (0);
}

void	unset_arg(char *str, t_shell *shell)
{
	int		line;
	char	**old;

	line = find_line(str, shell->envp);
	if (line >= 0)
	{
		old = shell->envp;
		shell->envp = array_remove_line(shell->envp, line);
		mem_free_array(old);
	}
}
