/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 17:26:21 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 08:52:50 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper/string.h"

char	*free_join(char *s1, char *s2)
{
	char	*new;

	if (!s1 || !s2)
		exit(error("Fatal error: NULL pointer passed in free join"));
	new = p(ft_strjoin(s1, s2));
	free(s1);
	free(s2);
	if (!new)
		return (NULL);
	return (new);
}

void	remove_char(char *str, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			str[x] = str[i];
			x++;
		}
		i++;
	}
	str[x] = '\0';
}
