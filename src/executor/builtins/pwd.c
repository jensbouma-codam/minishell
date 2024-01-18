/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 17:05:29 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/12/21 12:41:59 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor/builtins/pwd.h"

int	pwd(t_pipe *pipe)
{
	char	*cwd;

	(void)pipe;
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		error("pwd");
		return (EXIT_FAILURE);
	}
	if (ft_putstr_fd(cwd, 1) && ft_putchar_fd('\n', 1) == -1)
		return (free(cwd), EXIT_FAILURE);
	free(cwd);
	return (EXIT_SUCCESS);
}
