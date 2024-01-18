/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 17:51:09 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 15:15:39 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

/**
 * @brief The strcat() and strncat() functions append a copy of the
 * null-terminated string s2 to the end of the null-terminated string s1,
 * then add a terminating `\0'.
 * The string s1 must have sufficient space to hold the result.
 * The strncat() function appends not more than n characters from s2,
 * and then adds a terminating `\0'.
 * The source and destination strings should not overlap,
 * as the behavior is undefined.
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t The strcat() and strncat() functions return the pointer s1.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			dst_length;
	const size_t	src_length = ft_strlen(src);
	size_t			x;

	x = 0;
	if (!dst && !dstsize)
		return (src_length);
	dst_length = ft_strlen(dst);
	if (dstsize < dst_length)
		return (dstsize + src_length);
	while (src[x] && (dst_length + x + 1) < dstsize)
	{
		dst[dst_length + x] = src[x];
		x++;
	}	
	dst[dst_length + x] = '\0';
	return (dst_length + src_length);
}
