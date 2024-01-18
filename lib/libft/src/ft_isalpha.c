/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:42:42 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 14:33:08 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief he isalpha() function tests for any character for which isupper(3)
 * or islower(3) is true.  The value of the argument must be representable as
 * an unsigned char or the value of EOF.
 * 
 * @param c 
 * @return int The function returns zero if the character tests false
 * and returns non-zero if the character tests true.
 */
int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
