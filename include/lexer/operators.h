/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operators.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 13:25:33 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 16:50:25 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATORS_H
# define OPERATORS_H

# include "types.h"

# include "libft.h"
# include "lexer/quotes.h"
# include "helper/mem.h"

int				get_double_operator(t_shell *shell, int i);
int				get_single_operator(t_shell *shell, int i);
t_token_type	get_double_operator_meta(char *str);
int				is_operator(char c);

#endif
