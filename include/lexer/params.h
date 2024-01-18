/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   params.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 15:09:05 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/12/21 12:33:31 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

# include "types.h"

# include "libft.h"
# include "helper/mem.h"
# include "lexer/quotes.h"

int	get_param(t_shell *shell, int i);

#endif
