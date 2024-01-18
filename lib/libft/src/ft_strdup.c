/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 17:17:10 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/13 15:40:37 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strdup() function allocates sufficient memory for a copy of the
 * string s1, does the copy, and returns a pointer to it.
 * The pointer may subsequently be used as an argument to the function free(3).
 * If insufficient memory is available, NULL is returned.
 * The strndup() function copies at most n characters from the string s1
 * always NUL terminating the copied string.
 * 
 * @param s1 
 * @return char* 
 */
char	*ft_strdup(const char *s1)
{
	const size_t	length = ft_strlen(s1) + 1;
	char			*ptr;

	ptr = ft_calloc(1, length);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s1, length);
	return (ptr);
}
