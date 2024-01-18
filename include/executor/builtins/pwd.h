/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/18 17:06:14 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/12/21 12:40:05 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PWD_H
# define PWD_H

# include <stdlib.h>
# include <unistd.h>

# include "types.h"

# include "libft.h"
# include "helper/error.h"

int	pwd(t_pipe *pipe);

#endif