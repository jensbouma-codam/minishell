/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 14:27:40 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/16 16:03:32 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include <stdlib.h>
# include <errno.h>
# include <string.h>

# include "types.h"

# include "libft.h"
# include "helper/string.h"
# include "helper/error.h"
# include "executor/builtins/env.h"

int	cd(t_pipe *pipe);

#endif