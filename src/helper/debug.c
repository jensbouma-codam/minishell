/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 18:41:21 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 10:09:53 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper/debug.h"

static void	test_leaks(void)
{
	if (system("leaks minishell"))
		printf("DEBUG: Leaks found\n");
	else
		printf("DEBUG: No leaks found\n");
}

void	debug(t_shell *shell, char *msg)
{
	if (shell->debug)
		printf("DEBUG: %s\n", msg);
}

void	init_debug(t_shell *shell)
{
	if (DEBUG >= 2)
	{
		printf("DEBUG: Debug level set to %d\n", DEBUG);
		debug(shell, "DEBUG: Activate leaks test on exit\n");
		atexit(test_leaks);
	}
}

void	print_shell(t_shell *shell)
{
	if (!shell->debug)
		return ;
	printf("Shell: { line: %s\"%s\"%s, exit_code: %s%d%s, exit: %s%d%s, \
		debug: %s%d%s, prompt: %s\"%s\"%s }\n",
		YELLOW, shell->line, RESET,
		BLUE, shell->exit_code, RESET,
		RED, shell->exit, RESET,
		RED, shell->debug, RESET,
		YELLOW, shell->prompt, RESET);
	printf("\nTokens:\n");
	print_list(shell->tokens, (void (*)(void *, int))print_token, 4);
	printf("\nTasks:\n");
	print_list(shell->tasks, (void (*)(void *, int))print_task, 4);
}
