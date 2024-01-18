/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 12:13:34 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 14:34:51 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief The tolower() function converts an upper-case letter
 * to the corresponding lower-case letter.  The argument must be representable
 * as an unsigned char or the value of EOF.
 * 
 * @param c 
 * @return int  If the argument is an upper-case letter, the tolower() function
 * returns the corresponding lower-case letter if there is one;
 * otherwise, the argument is returned unchanged.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
