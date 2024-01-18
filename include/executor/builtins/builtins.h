/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 13:47:48 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/16 18:20:04 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdio.h>

# include "types.h"

# include "helper/array.h"
# include "helper/int.h"

# include "executor/builtins/echo.h"
# include "executor/builtins/cd.h"
# include "executor/builtins/pwd.h"
# include "executor/builtins/exports.h"
# include "executor/builtins/env.h"
# include "executor/builtins/exit.h"
# include "executor/builtins/unset.h"

bool	buildin(t_shell *shell, t_pipe *pipe);

#endif
