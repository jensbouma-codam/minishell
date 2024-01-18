/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 22:20:20 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 15:16:04 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Applies the function ’f’ on each character of
 * the string passed as argument, passing its index
 * as first argument.  Each character is passed by
 * address to ’f’ to be modified if necessary.
 * 
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (!s || !f)
		return ;
	i = -1;
	while (s[++i])
		f(i, &s[i]);
}
