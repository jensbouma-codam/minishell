/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 17:43:41 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/13 15:47:05 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string ’s’.
 * The substring begins at index ’start’ and is of maximum size ’len’
 * 
 * @param s 
 * @param start The string from which to create the substring.
 * start:  The start index of the substring in the string ’s’.
 * @param len The maximum length of the substring.
 * @return char* The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	strlen;
	char	*substring;

	if (!s)
		return (0);
	strlen = ft_strlen(s);
	if ((start >= strlen) || len == 0)
		return (ft_calloc(sizeof(char), 1));
	if (strlen - start <= len)
		substring = ft_calloc(sizeof(char), (strlen - start) + 1);
	else
		substring = ft_calloc(sizeof(char), len + 1);
	if (!substring)
		return (0);
	if (len >= ULONG_MAX)
		ft_strlcpy(substring, s + start, strlen + 1);
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}
