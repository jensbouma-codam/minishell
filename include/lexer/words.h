/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   words.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 13:25:33 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/12/21 12:33:38 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDS_H
# define WORDS_H

# include "types.h"

# include "libft.h"
# include "lexer/quotes.h"
# include "lexer/operators.h"
# include "helper/mem.h"

int	get_word(t_shell *shell, int i);

#endif
