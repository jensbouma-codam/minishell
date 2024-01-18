/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/27 15:01:31 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/22 14:11:49 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	*ft_strcat(char *s1, char *s2)
{
	char			*new;
	size_t			i;
	size_t			x;

	new = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!new)
		return (free(s1), NULL);
	i = 0;
	x = 0;
	while (s1 && s1[i])
	{
		new[i++] = s1[x];
		s1[x++] = '\0';
	}
	x = 0;
	while (s2 && s2[x])
	{
		new[i++] = s2[x];
		s2[x++] = '\0';
	}
	return (free(s1), new);
}

char	*ret_empty(char *s)
{
	s[0] = '\0';
	return (NULL);
}
