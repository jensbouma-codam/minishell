/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 14:24:28 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/16 14:44:54 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "types.h"

# include "libft.h"
# include "cleanup.h"
# include "helper/mem.h"
# include "helper/debug.h"
# include "helper/int.h"
# include "helper/string.h"

# include "executor/expander/expander.h"
# include "executor/redirects/redirects.h"
# include "executor/fork.h"

bool	executor(t_shell *shell);

#endif
