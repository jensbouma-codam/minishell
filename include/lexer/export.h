/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 14:01:47 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/12/21 12:32:58 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include "types.h"

# include "lexer/operators.h"
# include "lexer/quotes.h"
# include "helper/debug.h"
# include "helper/string.h"

int	get_exports(t_shell *shell, int i);

#endif