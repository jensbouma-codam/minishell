/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 18:39:27 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 12:37:18 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <stdlib.h>

# include "types.h"
# include "libft.h"
# include "helper/error.h"
# include "helper/debug.h"
# include "helper/string.h"

int	exits(t_pipe *pipe);

#endif