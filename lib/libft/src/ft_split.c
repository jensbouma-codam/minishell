/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 17:09:49 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/22 13:27:39 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter.  The array must end
 * with a NULL pointer.
 * 
 * @param s String of characters
 * @param c Character to split string
 * @return char**  Array of splited parts
 */
static size_t	get_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len + 1);
}

static size_t	find_parts(char const *s, char set)
{
	size_t		parts;
	int			found;

	parts = 0;
	while (*s)
	{
		found = 0;
		while (*s && *s++ != set)
			found = 1;
		while (*s && *s == set)
			s++;
		if (found)
			parts++;
	}
	return (parts);
}

static char	**free_allocation(char **array, size_t parts)
{
	while (parts)
		free(array[parts--]);
	free(array[0]);
	free(array);
	return (0);
}

static char	**fill_array(char **array, char *s, char c, size_t parts)
{
	size_t	i;
	size_t	x;

	i = 0;
	while (i != parts)
	{
		while (*s && *s == c)
			s++;
		if (*s != c)
		{
			array[i] = ft_calloc(get_len(s, c), sizeof(char));
			if (!array[i])
				return (free_allocation(array, i));
		}
		x = 0;
		while (*s && *s != c)
			array[i][x++] = *s++;
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	parts;

	if (!s)
		return (0);
	parts = find_parts(s, c);
	array = (char **)ft_calloc(parts + 1, sizeof(char *));
	if (!array)
		return (0);
	return (fill_array(array, (char *)s, c, parts));
}
