/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 14:02:45 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 15:14:34 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * @brief 
 * The strnstr() function locates the first occurrence of the null-terminated 
 * string needle in the string haystack. 
 * Where not more than len characters are searched.
 * 
 * Characters that appear after a `\0' character are not searched.
 * @param haystack 	String to search ing
 * @param needle 	String to find
 * @param len 		Max seach length
 * @return char*
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*find;
	char	*source;
	size_t	rest_len;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		source = (char *)haystack;
		find = (char *)needle;
		rest_len = len;
		while (*source++ == *find++ && rest_len--)
		{
			if (*find == '\0')
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}
