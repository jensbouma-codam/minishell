/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   array.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 00:24:47 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/12/21 12:04:10 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stdlib.h>

# include "libft.h"
# include "helper/mem.h"

int		array_len(char **array);
int		array_find(char *needle, char **haystack);
char	**array_add_back(char **strs, const char *str);
char	**array_remove_line(char **strs, int line);
char	**array_sort(char **array);

#endif