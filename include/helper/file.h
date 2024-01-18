/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 16:35:05 by jbouma        #+#    #+#                 */
/*   Updated: 2024/01/17 23:37:20 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>

# include <dirent.h>

# include "types.h"
# include "executor/builtins/env.h"
# include "helper/string.h"

char	*where(char *arg, t_shell *shell);
char	*file_searchpath(char *filename, char *envp[]);
bool	valid_file(t_shell *shell, char *file);

#endif