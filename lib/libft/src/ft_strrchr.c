/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 12:52:24 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 14:34:43 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief he strchr() function locates the first occurrence of c
 * (converted to a char) in the string pointed to by s.
 * The terminating null character is considered to be part of the string;
 * therefore if c is `\0', the functions locate the terminating `\0'.
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*buf;

	buf = 0;
	while (*s)
	{	
		if ((char)*s == (unsigned char)c)
			buf = (char *)s;
		s++;
	}
	if ((unsigned char)c)
		return (buf);
	return ((char *)s);
}
