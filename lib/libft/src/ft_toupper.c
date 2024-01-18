/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 12:13:34 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 14:34:54 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief The toupper() function converts a lower-case letter to the
 * corresponding upper-case letter.  The argument must be representable
 * as an unsigned char or the value of EOF.
 * 
 * @param c 
 * @return int If the argument is a lower-case letter, the toupper()
 * function returns the corresponding upper-case letter if there is one;
 * otherwise, the argument is returned unchanged.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
