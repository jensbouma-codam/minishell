/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mem.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 13:56:02 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 23:33:14 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <stdlib.h>

# include "types.h"
# include "libft.h"
# include "helper/error.h"
# include "helper/array.h"

void	*mem_calloc(size_t count, size_t size);
void	*mem_realloc(void *ptr, size_t size);
void	*p(void *ptr);
char	**mem_cpy_array(char **src);
void	mem_free_array(char **arr);

#endif
