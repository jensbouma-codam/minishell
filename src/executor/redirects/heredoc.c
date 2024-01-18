/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/15 11:20:17 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 10:33:34 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor/redirects/heredoc.h"

static	int	parse_stop(char *stop)
{
	int	i;

	i = ft_strlen(stop);
	if (stop[i - 1] == '\"')
	{
		remove_char(stop, '\"');
		return (DQUOTE);
	}
	else if (stop[i - 1] == '\'')
	{
		remove_char(stop, '\'');
		return (QUOTE);
	}
	return (WORD);
}

static void	heredoc_read(int fd, char *stop, t_shell *shell)
{
	char	*line;
	int		type;
	char	*ret;

	type = parse_stop(stop);
	while (1)
	{
		line = readline("heredoc> ");
		if (!line)
			return ;
		if (ft_strcmp(line, stop) == 0)
			break ;
		if (type != DQUOTE)
		{
			ret = expand_string(line, shell);
			ft_putstr_fd(ret, fd);
			ft_putstr_fd("\n", fd);
			free(ret);
			continue ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	free(line);
}

static void	add_tokens(t_shell *shell, char *filename)
{
	t_token	*token;

	token = mem_calloc(1, sizeof(t_token));
	token->value = p(ft_strdup("<"));
	token->type = LESS;
	ft_lstadd_back(&shell->tokens, p(ft_lstnew(token)));
	token = mem_calloc(1, sizeof(t_token));
	token->value = p(ft_strdup(filename));
	token->type = WORD;
	ft_lstadd_back(&shell->tokens, p(ft_lstnew(token)));
}

static int	heredoc_open(t_shell *shell, char *stop)
{
	static int	increment = 0;	
	int			fd;
	char		*filename;

	filename = free_join(ft_strdup(".heredoc"), ft_itoa(increment));
	increment++;
	debug(shell, "heredoc_open");
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("heredoc_open: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		shell->exit_code = 126;
		return (-1);
	}
	heredoc_read(fd, stop, shell);
	close(fd);
	add_tokens(shell, filename);
	return (free(filename), fd);
}

int	heredoc(t_shell *shell, int i)
{
	char	*stop;
	int		len;
	int		x;

	x = i;
	len = 0;
	if (!is_quote(&shell->line[i])
		&& get_double_operator_meta(&shell->line[i]) == DLESS
		&& (shell->line[i + 2])
	)
	{
		x += 2;
		while (shell->line[x] && shell->line[x] == ' ')
			x++;
		while (shell->line[x + len] && shell->line[x + len] != ' '
			&& shell->line[x + len] != '\n' && shell->line[x + len] != '>'
			&& shell->line[x + len] != '<' && shell->line[x + len] != '|')
			len++;
		stop = p(ft_substr(shell->line, x, len));
		heredoc_open(shell, stop);
		free(stop);
		return (x + len - i);
	}
	return (0);
}
