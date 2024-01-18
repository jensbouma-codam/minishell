/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   external.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 16:27:08 by jbouma        #+#    #+#                 */
/*   Updated: 2024/01/18 16:02:18 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor/external.h"

static bool	is_valid_executable(char *path, t_shell *shell)
{
	struct stat	buf;

	shell->exit_code = 127;
	if (stat(path, &buf) == 0)
	{
		if (S_ISDIR(buf.st_mode))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(path, 2);
			ft_putendl_fd(": Is a directory", 2);
			if (access(path, X_OK) == 0 || path[0] == '.' || path[0] == '~')
				shell->exit_code = 126;
			return (FALSE);
		}
		if (access(path, X_OK) == 0)
			return (TRUE);
		shell->exit_code = 126;
	}
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	return (FALSE);
}

static int	execve_error(t_pipe *pipe)
{
	ft_putstr_fd("Executev error ", 2);
	ft_putstr_fd(pipe->argv[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(errno, 2);
	ft_putchar_fd('\n', 2);
	if (errno == 13)
		return (126);
	else if (errno == 2)
		return (127);
	return (errno + 128);
}

static int	exec(char *executable, t_shell *shell, t_pipe *pipe)
{
	char	**envp;
	char	*env;

	if (!is_valid_executable(executable, shell))
	{
		free(executable);
		return (shell->exit_code);
	}
	env = ft_strjoin("_=", executable);
	envp = array_add_back(pipe->envp, env);
	free(env);
	if (execve(executable, pipe->argv, envp) != 0)
		return (execve_error(pipe));
	free(executable);
	return (EXIT_SUCCESS);
}

int	execute_external_cmd(t_shell *shell, t_pipe *pipe)
{
	char	*executable;

	if (pipe->argc == 0)
		return (EXIT_SUCCESS);
	if (pipe->argv[0][0] == '/' || pipe->argv[0][0] == '~'
		|| pipe->argv[0][0] == '.' || pipe->argv[0][0] == '\0')
		executable = p(ft_strdup(pipe->argv[0]));
	else
		executable = where(pipe->argv[0], shell);
	if (!executable)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(pipe->argv[0], 2);
		ft_putendl_fd(": command not found", 2);
		return (127);
	}
	return (exec(executable, shell, pipe));
}
