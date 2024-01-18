/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 13:54:14 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 14:33:52 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief The memcpy() function copies n bytes from memory area src
 * to memory area dst.  If dst and src overlap, behavior is undefined.
 * Applications in which dst and src might overlap should use memmove(3) instead.
 * 
 * @param dst 
 * @param src 
 * @param n 
 * @return void* The memcpy() function returns the original value of dst.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!n || dst == src)
		return (dst);
	while (n--)
	{
		((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dst);
}
