/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/03 16:12:44 by jbouma        #+#    #+#                 */
/*   Updated: 2024/01/18 17:45:12 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor/builtins/cd.h"

bool	update_path(char *path, t_pipe *pipe)
{
	char	*oldpwd;
	char	*pwd;
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (tmp)
		oldpwd = free_join(ft_strdup("OLDPWD="), tmp);
	else
		oldpwd = p(free_join(ft_strdup("OLDPWD="), ft_strdup(path)));
	env_set(oldpwd, &pipe->envp);
	if (chdir(path) == 0)
	{
		pwd = free_join(ft_strdup("PWD="), getcwd(NULL, 0));
		env_set(pwd, &pipe->envp);
		return (free(pwd), free(oldpwd), free(path), EXIT_SUCCESS);
	}
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	return (free(path), free(oldpwd), EXIT_FAILURE);
}

/**
 * @brief Change path to the given path or HOME if no path is given.
 * 
 * @param shell 
 * @return int returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	cd(t_pipe *pipe)
{
	char	*path;

	if (pipe->argc == 1)
		path = env_get("HOME", pipe->envp);
	else if (pipe->argc == 2)
	{
		if (ft_strcmp(pipe->argv[1], "~") == 0
			|| ft_strcmp(pipe->argv[1], "--") == 0)
			path = env_get("HOME", pipe->envp);
		else if (ft_strcmp(pipe->argv[1], "-") == 0)
		{
			path = env_get("OLDPWD", pipe->envp);
			ft_putendl_fd(path, 1);
		}
		else
			path = p(ft_strdup(pipe->argv[1]));
	}
	else
	{
		ft_putendl_fd("cd: too many arguments", 2);
		return (EXIT_FAILURE);
	}
	return (update_path(path, pipe));
}
