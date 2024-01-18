/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/19 17:57:58 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 23:50:25 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_H
# define UNSET_H

# include "types.h"

# include "libft.h"
# include "helper/mem.h"
# include "helper/array.h"

int		unset(t_pipe *pipe);
void	unset_arg(char *str, t_shell *shell);

#endif