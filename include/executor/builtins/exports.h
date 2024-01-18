/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exports.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 17:17:05 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 16:07:12 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORTS_H
# define EXPORTS_H

# include "types.h"

# include "libft.h"
# include "helper/array.h"
# include "helper/mem.h"
# include "executor/builtins/env.h"
# include "helper/printer.h"

int	exports(t_pipe *pipe);

#endif
