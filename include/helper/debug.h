/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 18:42:14 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 09:22:17 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <stdio.h>
# include <stdlib.h>

# include "types.h"
# include "libft.h"
# include "helper/printer.h"
# include "helper/debug.h"

void	debug(t_shell *shell, char *msg);
void	init_debug(t_shell *shell);
void	print_shell(t_shell *shell);

#endif
