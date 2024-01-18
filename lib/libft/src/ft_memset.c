/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:23:32 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 15:14:02 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief The memset() function writes len bytes of value c (converted
 * to an unsigned char) to the string b.

 * 
 * @param b 
 * @param c 
 * @param len 
 * @return void* The memset() function returns its first argument.
 */
void	*ft_memset(void *b, int c, size_t len)
{	
	while (len-- > 0)
		((unsigned char *)b)[len] = (unsigned char) c;
	return (b);
}
