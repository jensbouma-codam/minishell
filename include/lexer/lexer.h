/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 12:45:35 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/12/21 12:33:24 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "types.h"

# include "lexer/operators.h"
# include "lexer/quotes.h"
# include "lexer/params.h"
# include "lexer/export.h"
# include "lexer/words.h"
# include "lexer/blanks.h"
# include "lexer/comments.h"

bool	lexer(t_shell *shell);

#endif
