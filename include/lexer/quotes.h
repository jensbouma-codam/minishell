/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotes.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 13:25:33 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/12/21 12:33:35 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTES_H
# define QUOTES_H

# include "types.h"

# include "libft.h"
# include "helper/debug.h"
# include "helper/mem.h"

int	is_quote(const char *str);
int	get_quote(t_shell *shell, int i);

#endif
