/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   blanks.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 13:25:33 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/12/21 12:33:02 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLANKS_H
# define BLANKS_H

# include "types.h"

# include "libft.h"
# include "lexer/quotes.h"
# include "helper/mem.h"

int	get_blank(t_shell *shell, int i);

#endif
