/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirects.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/22 13:02:56 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 23:37:45 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTS_H
# define REDIRECTS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

# include "libft.h"
# include "types.h"

# include "helper/string.h"
# include "helper/int.h"
# include "executor/redirects/heredoc.h"
# include "helper/file.h"

bool	redirect(t_shell *shell, t_pipe *pipe);
bool	close_redirect(t_pipe *task);

#endif