/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 12:09:37 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 14:34:14 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief The strchr() function locates the first occurrence of c
 * (converted to a char) in the string pointed to by s.
 * The terminating null character is considered to be part of the string;
 * therefore if c is `\0', the functions locate the terminating `\0'.
 * 
 * @param s 
 * @param c 
 * @return char*  The functions strchr() and strrchr() return a pointer to the
 * located character, or NULL if the character does not appear in the string.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s && (char)*s != (unsigned char)c)
		s++;
	if ((char)*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}
