/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 20:24:40 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/22 14:46:19 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief The memchr() function locates the first occurrence of c
 *  (converted to an unsigned char) in string s.
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return void* The memchr() function returns a pointer to the byte located,
 * or NULL if no such byte exists within n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	p;

	p = 0;
	while (p < n)
	{
		if (((const unsigned char *)s)[p] == (unsigned char)c)
			return ((void *)s + p);
		p++;
	}
	return (0);
}
