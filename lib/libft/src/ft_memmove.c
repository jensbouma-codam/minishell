/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 14:34:17 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/22 13:23:00 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The memmove() function copies len bytes from string src to string dst.
 * The two strings may overlap the copy is always done
 *  in a non-destructive manner.
 * 
 * @param dst 
 * @param src 
 * @param len 
 * @return void* The memmove() function returns the original value of dst.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (0);
	if (src < dst)
	{
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
