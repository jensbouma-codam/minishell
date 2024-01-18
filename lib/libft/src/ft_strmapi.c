/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 22:20:20 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/13 15:40:45 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function ’f’ to each character of the
 * string ’s’, and passing its index as first argument
 * to create a new string (with malloc(3)) resulting
 * from successive applications of ’f’.
 * 
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return char* The string created from the successive applications
 * of ’f’. Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!buffer)
		return (0);
	ft_memcpy(buffer, s, ft_strlen(s));
	while (buffer[i])
	{
		buffer[i] = (*f)(i, buffer[i]);
		i++;
	}
	return (buffer);
}
