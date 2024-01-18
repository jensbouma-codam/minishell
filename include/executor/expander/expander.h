/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/13 15:49:11 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 15:17:12 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <stdlib.h>
# include <stdio.h>

# include "types.h"

# include "libft.h"
# include "helper/mem.h"
# include "helper/string.h"
# include "helper/array.h"
# include "executor/builtins/env.h"
# include "cleanup.h"

void	expander(t_task *pipe, t_shell *shell);
char	*expand_string(char *str, t_shell *shell);

#endif