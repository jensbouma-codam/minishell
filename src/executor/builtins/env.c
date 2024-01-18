/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 14:36:07 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 23:33:14 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor/builtins/env.h"

char	**env_get_searchpaths(char *envp[])
{
	int		i;
	char	**searchpaths;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			searchpaths = p(ft_split(envp[i] + 5, ':'));
			if (!searchpaths)
				return (NULL);
			return (searchpaths);
		}
		i++;
	}
	return (NULL);
}

char	*env_get(char *str, char **envp)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], str, ft_strlen(str)) == 0
			&& envp[i][ft_strlen(str)] == '=')
		{
			while (envp[i][length] != '\0')
				length++;
			return (p(ft_substr(envp[i], ft_strlen(str) + 1, length)));
		}
		i++;
	}
	return (p(ft_strdup("")));
}

static int	env_add(char *str, char ***ptr)
{
	char	**new;
	int		size;

	size = array_len(*ptr);
	new = mem_calloc((size + 2), sizeof(char *));
	new[size] = p(ft_strdup(str));
	while (size)
	{
		size--;
		new[size] = p(ft_strdup((*ptr)[size]));
	}
	mem_free_array(*ptr);
	*ptr = new;
	return (EXIT_SUCCESS);
}

int	env_set(char *str, char ***ptr)
{
	char	**envp;
	int		i;
	char	**array;

	envp = *ptr;
	i = 0;
	array = p(ft_split(str, '='));
	while (envp[i])
	{
		if (ft_strncmp(envp[i], array[0], ft_strlen(array[0])) == 0)
		{
			free(envp[i]);
			envp[i] = p(ft_strdup(str));
			mem_free_array(array);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	mem_free_array(array);
	return (env_add(str, ptr));
}

/**
 * @brief env with no options or arguments
 * 
 * @param envp 
 */
int	env(t_pipe *pipe)
{
	return (print_array(pipe->envp));
}
