/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:50:20 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 14:33:11 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief The isascii() function tests for an ASCII character,
 * which is any character between 0 and octal 0177 inclusive.
 * 
 * @param c 
 * @return int The function returns zero if the character tests false
 * and returns non-zero if the character tests true.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
