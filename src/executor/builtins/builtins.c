/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 13:48:03 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 00:02:46 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor/builtins/builtins.h"

bool	buildin(t_shell *shell, t_pipe *cmd)
{
	int			index;
	static char	*builtins[8] = {
		"echo", "cd", "pwd", "export", "env", "exit", "unset", NULL};
	static int	(*buildin_functions[8])(t_pipe *) = {
		&b_echo, &cd, &pwd, &exports, &env, &exits, &unset, NULL};

	index = array_find(cmd->argv[0], builtins);
	if (index == -1)
		return (FALSE);
	shell->exit_code = buildin_functions[index](cmd);
	if (index == 5)
		shell->exit = TRUE;
	else
		shell->exit = FALSE;
	return (TRUE);
}
