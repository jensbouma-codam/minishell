/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 16:34:12 by jbouma        #+#    #+#                 */
/*   Updated: 2024/01/17 23:37:38 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper/file.h"

static bool	file_in_dir(char *searchpath, char *filename)
{
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(searchpath);
	if (!dir)
		return (FALSE);
	entry = readdir(dir);
	while (entry)
	{
		if (ft_strcmp(entry->d_name, filename) == 0)
		{
			closedir(dir);
			return (TRUE);
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (FALSE);
}

char	*file_searchpath(char *filename, char *envp[])
{
	char	**searchpath;

	searchpath = env_get_searchpaths(envp);
	while (*searchpath)
	{
		if (file_in_dir(*searchpath, filename))
			return (*searchpath);
		searchpath++;
	}
	return (NULL);
}

char	*where(char *arg, t_shell *shell)
{
	const char	**paths = (const char **)env_get_searchpaths(shell->envp);
	char		*new_path;
	struct stat	buf;
	int			i;

	i = 0;
	new_path = NULL;
	if (stat(arg, &buf) == 0 && ft_strchr(arg, '/') != NULL)
		new_path = p(ft_strdup(arg));
	else
	{
		while (paths && paths[i])
		{
			new_path = free_join(ft_strjoin(paths[i], "/"), ft_strdup(arg));
			if (stat(new_path, &buf) == 0)
				break ;
			free(new_path);
			new_path = NULL;
			i++;
		}
	}
	i = 0;
	mem_free_array((char **)paths);
	return (new_path);
}

bool	valid_file(t_shell *shell, char *file)
{
	struct stat	buf;

	if (stat(file, &buf) == 0)
	{
		if (S_ISDIR(buf.st_mode))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(file, 2);
			ft_putstr_fd(": Is a directory\n", 2);
			shell->exit_code = 126;
			return (FALSE);
		}
		else if (access(file, W_OK) != 0)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(file, 2);
			ft_putstr_fd(": Permission denied\n", 2);
			shell->exit_code = 126;
			return (FALSE);
		}
		return (TRUE);
	}
	return (TRUE);
}
