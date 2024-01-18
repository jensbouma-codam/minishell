/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 14:02:45 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/13 15:36:03 by jbouma        ########   odam.nl         */
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
char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*find;
	char	*source;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		source = (char *)haystack;
		find = (char *)needle;
		while (*source++ == *find++)
		{
			if (*find == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (0);
}
