/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 13:28:11 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/16 16:06:46 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "types.h"

# include "libft.h"
# include "helper/mem.h"
# include "helper/int.h"
# include "parser/validate.h"
# include "helper/debug.h"

# include "executor/redirects/heredoc.h"

bool	parser(t_shell *shell);

#endif
