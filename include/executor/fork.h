/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/16 14:22:19 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/16 22:08:25 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include "libft.h"

# include "cleanup.h"
# include "helper/mem.h"
# include "helper/debug.h"
# include "helper/int.h"
# include "helper/string.h"
# include "minishell.h"

# include "executor/expander/expander.h"
# include "executor/builtins/builtins.h"
# include "executor/redirects/redirects.h"
# include "executor/external.h"
# include "executor/fork.h"
# include "signals.h"

void	execute_cmd(t_shell *shell, t_list *pipes, t_pipe *cmd);

#endif