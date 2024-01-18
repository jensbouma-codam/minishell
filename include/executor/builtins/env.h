/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 14:35:31 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 12:15:52 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "types.h"

# include "libft.h"
# include "helper/mem.h"
# include "helper/array.h"
# include "helper/printer.h"

char	**env_get_searchpaths(char *envp[]);
char	*env_get(char *str, char **envp);
int		env_set(char *str, char ***envp);
int		env(t_pipe *pipe);

#endif
