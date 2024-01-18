/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 15:20:18 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 17:48:02 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	clean_exit(t_shell *shell)
{
	const int	exit_code = shell->exit_code;

	rl_clear_history();
	mem_free_array(shell->args);
	mem_free_array(shell->envp);
	if (shell->prompt)
		free(shell->prompt);
	if (shell->tokens)
		ft_lstclear(&shell->tokens, free_t_token);
	if (shell->tasks)
		ft_lstclear(&shell->tasks, free_t_tasks);
	if (shell->line)
		free(shell->line);
	free(shell);
	return (exit_code);
}

static t_shell	*init(const int argc, const char **argv, const char **envp)
{
	t_shell	*shell;
	char	*shlvl;
	char	*tmp;

	shell = mem_calloc(1, sizeof(t_shell));
	shell->debug = FALSE;
	shell->exit_code = 0;
	shell->exit = FALSE;
	shell->line = NULL;
	if ((argc > 1 && ft_strcmp(argv[1], "-d") == 0) || DEBUG > 0)
	{
		ft_putstr_fd("DEBUG: Debug mode activated\n", 1);
		shell->debug = TRUE;
	}
	shell->args = mem_cpy_array((char **)argv);
	shell->envp = mem_cpy_array((char **)envp);
	shlvl = env_get("SHLVL", shell->envp);
	tmp = free_join(ft_strdup("SHLVL="), ft_itoa(ft_atoi(shlvl) + 1));
	env_set(tmp, &shell->envp);
	unset_arg("_", shell);
	return (free(shlvl), free(tmp), shell);
}

static void	set_prompt(t_shell *shell)
{
	if (shell->prompt)
		free(shell->prompt);
	shell->prompt = free_join(env_get("USER", shell->envp),
			p(ft_strdup(" @ ")));
	if (ft_strcmp(shell->prompt, " @ ") == 0)
	{
		free(shell->prompt);
		shell->prompt = p(ft_strdup(""));
	}
	shell->prompt = free_join(shell->prompt, env_get("PWD", shell->envp));
	shell->prompt = free_join(shell->prompt,
			p(ft_strdup(" ¯\\_(ツ)_/¯ ")));
}

static void	process_input(t_shell *shell)
{
	if ((!lexer(shell) || !validate(shell->tokens) || !parser(shell)))
		shell->exit_code = 2;
	else
	{
		add_history(shell->line);
		executor(shell);
		if (shell->debug)
			print_shell(shell);
	}
	ft_lstclear(&shell->tokens, free_t_token);
	ft_lstclear(&shell->tasks, free_t_tasks);
	free(shell->line);
	shell->line = NULL;
}

int	main(const int argc, char const **argv, char const **env)
{
	t_shell	*shell;

	shell = init(argc, argv, env);
	init_debug(shell);
	signal_init();
	if (!isatty(STDIN_FILENO))
		rl_outstream = stdin;
	while (!shell->exit || !isatty(STDIN_FILENO))
	{
		set_prompt(shell);
		shell->line = readline(shell->prompt);
		if (shell->line && shell->line[0])
			process_input(shell);
		else if (!shell->line)
			break ;
	}
	return (clean_exit(shell));
}
