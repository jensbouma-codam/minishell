/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   types.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 13:01:56 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 00:10:35 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <sys/types.h>
# include <stdbool.h>
# include "libft.h"

typedef enum e_token_type
{
	NONE,
	WORD,
	NAME,
	AND_IF,
	OR_IF,
	DSEMI,
	DLESS,
	DGREAT,
	LESSAND,
	GREATAND,
	LESSGREAT,
	PARAM,
	PIPE,
	SEMICOLON,
	COMMENT,
	LESS,
	GREAT,
	BLANK,
	AND,
	CLOBBER,
	QUOTE,
	DQUOTE,
	EXPORT,
	COMMAND,
	ARGUMENT,
	NEWL
}	t_token_type;

typedef struct s_token
{
	int		type;
	char	*value;
}	t_token;

typedef struct s_task
{
	int		index;
	t_list	*tokens;
	t_list	*pipes;
}	t_task;

typedef struct s_redirect
{
	int				index;
	int				type;
	char			*file;
	t_list			*tokens;
}	t_redirect;

typedef struct s_pipe
{
	int				index;
	bool			exited;
	int				fd[2];
	int				prev_fd[2];
	pid_t			pid;
	int				status;
	t_list			*tokens;
	t_list			*redirects;
	int				redirect[2];
	char			**envp;
	char			**argv;
	int				argc;
}	t_pipe;

typedef struct s_shell
{
	char	*line;
	char	**args;
	char	**envp;
	int		exit_code;
	bool	exit;
	bool	debug;
	bool	interactive;
	char	*prompt;
	int		fd[2];
	t_list	*tokens;
	t_list	*tasks;
}	t_shell;

# define ERR_UNKOWN "Unkown error"
# define CD_ERR "bash: cd: "

#endif
