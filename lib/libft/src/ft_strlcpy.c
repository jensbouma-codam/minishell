/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 17:26:30 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 15:15:24 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

/**
 * @brief The strlcpy() copies strings with the same input parameters
 * and output result as. 
 * They are designed to be safer, more consistent, and less error prone
 * replacements for the easily misused functions strncpy(3) and strncat(3).
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t Returns the total length of the string they tried to create.
 * For strlcpy() that means the length of src.
 * If the return value is >= dstsize, the output string has been truncated.
 * It is the caller's responsibility to handle this.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	const size_t	srcsize = ft_strlen(src);

	i = 0;
	if (!dstsize)
		return (srcsize);
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}
