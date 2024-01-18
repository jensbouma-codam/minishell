/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 17:27:33 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 08:34:05 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stdlib.h>
# include "libft.h"
# include "helper/mem.h"

char	*free_join(char *s1, char *s2);
void	remove_char(char *str, char c);

#endif
