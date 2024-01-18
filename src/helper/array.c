/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   array.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/14 00:24:20 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 11:03:06 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper/array.h"

/**
 * Calculates the length of a null-terminated array of strings.
 *
 * @param array The array of strings.
 * @return The length of the array.
 */
int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

/**
 * Finds the index of a string in an array of strings.
 *
 * @param needle The string to search for.
 * @param haystack The array of strings to search in.
 * @return The index of the first occurrence of the string in the array,
 *         or -1 if the string is not found.
 */
int	array_find(char *needle, char **haystack)
{
	int	i;

	i = 0;
	while (needle && needle[0] && haystack[i])
	{
		if (ft_strcmp(haystack[i], needle) == 0)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * Adds a string to the back of an array of strings.
 *
 * @param strs The array of strings to which the string will be added.
 * @param str The string to be added to the array.
 * @return The updated array of strings with the new string added at the back.
 */
char	**array_add_back(char **strs, const char *str)
{
	int		i;
	char	**ret;

	ret = mem_calloc(array_len(strs) + 2, sizeof(char *));
	if (!ret)
		return (0);
	i = 0;
	while (strs[i])
	{
		ret[i] = p(ft_strdup(strs[i]));
		i++;
	}
	ret[i++] = p(ft_strdup(str));
	ret[i] = 0;
	return (ret);
}

/**
 * Removes a line from a string array.
 *
 * @param strs The string array from which to remove the line.
 * @param line The index of the line to be removed.
 * @return A new string array with the specified line removed,
 * or NULL if memory allocation fails.
 */
char	**array_remove_line(char **strs, int line)
{
	int		i;
	int		j;
	char	**ret;

	ret = mem_calloc(array_len(strs), sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (strs[i])
	{
		if (i == line)
			i++;
		if (strs[i])
		{
			ret[j] = p(ft_strdup(strs[i]));
			i++;
			j++;
		}
		if (i == line)
			i++;
	}
	ret[j] = NULL;
	return (ret);
}

/**
 * Sorts an array of strings in lexicographical order.
 *
 * @param array The array of strings to be sorted.
 * @return The sorted array of strings.
 */
char	**array_sort(char **array)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (ft_strcmp(array[i], array[j]) > 0)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array);
}
