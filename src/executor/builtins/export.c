/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahornstr <ahornstr@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/26 13:32:46 by ahornstr      #+#    #+#                 */
/*   Updated: 2024/01/18 16:10:33 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor/builtins/exports.h"

static char	**split_key_value(char *key_value)
{
	char	**split;
	int		i;

	i = 0;
	while (key_value[i] && key_value[i] != '=')
		i++;
	split = p(ft_calloc(3, sizeof(char *)));
	split[0] = p(ft_substr(key_value, 0, i));
	split[1] = p(ft_substr(key_value, i + 1, ft_strlen(key_value)));
	return (split);
}

static int	test_more(char **split, char *argv)
{
	int		i;

	i = 1;
	while (split[0][i])
	{
		if (ft_isalnum(split[0][i]) || split[0][i] == '_' || split[0][i] == '+'
			|| split[0][i] == '-')
		{
			i++;
			continue ;
		}
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(argv, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		mem_free_array(split);
		return (1);
	}
	mem_free_array(split);
	return (EXIT_SUCCESS);
}

static int	test_errors(char *argv)
{
	char	**split;

	split = split_key_value(argv);
	if ((argv[0] == '=')
		|| (ft_isdigit(split[0][0]) || ft_strchr(split[0], '+')
		|| ft_strchr(split[0], '-')) || ft_strchr(split[0], '?'))
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(argv, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		mem_free_array(split);
		if (argv[0] == '-')
			return (2);
		return (1);
	}
	return (test_more(split, argv));
}

static int	export_add(char **argv, char ***envp)
{
	int		i;
	int		exit_code;

	i = 1;
	exit_code = EXIT_SUCCESS;
	while (argv[i])
	{
		exit_code = test_errors(argv[i]);
		if (exit_code == EXIT_SUCCESS)
			env_set(argv[i], envp);
		i++;
	}
	return (exit_code);
}

int	exports(t_pipe *pipe)
{
	char	**sorted_env;

	if (array_len(pipe->argv) > 1)
		return (export_add(pipe->argv, &pipe->envp));
	else
	{
		sorted_env = mem_cpy_array(pipe->envp);
		if (!sorted_env)
			return (EXIT_FAILURE);
		print_array_export(array_sort(sorted_env));
		mem_free_array(sorted_env);
	}
	return (EXIT_SUCCESS);
}
