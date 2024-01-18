/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 14:01:16 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 19:07:30 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H

# include <stdio.h>
# include <stdlib.h>

# include "types.h"

# include "libft.h"

# include "executor/builtins/env.h"

int	b_echo(t_pipe *pipe);

#endif
