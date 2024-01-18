/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   external.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 16:27:21 by jbouma        #+#    #+#                 */
/*   Updated: 2024/01/15 11:57:57 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERNAL_H
# define EXTERNAL_H

# include "types.h"

# include "libft.h"
# include "helper/mem.h"
# include "helper/debug.h"
# include "helper/int.h"
# include "helper/string.h"

# include <stdlib.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/wait.h>
// # include <sys/stat.h>

# include <errno.h>
# include <string.h>

// # include <dirent.h>

# include "builtins/env.h"
# include "executor/redirects/redirects.h"
# include "helper/file.h"

int	execute_external_cmd(t_shell *shell, t_pipe *pipe);

#endif