/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 13:57:51 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/12/12 14:30:04 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>

# include "types.h"
# include "libft.h"

int	error(char *str);

#endif
