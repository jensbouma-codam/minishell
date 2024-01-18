/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mem.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 13:52:45 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/17 23:33:14 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper/mem.h"
#include "string.h"

/**
 * @brief Checks if a pointer is valid and returns it.
 * 
 * This function checks if the given pointer is not NULL and returns it.
 * If the pointer is NULL, it calls the error function and exits the program
 * with a failure status.
 * 
 * @param ptr The pointer to be checked.
 * @return The valid pointer.
 */
void	*p(void *ptr)
{
	if (ptr)
		return (ptr);
	exit(error("Fatal error during memory allocation"));
}

/**
 * Allocates memory for an array of elements and initializes them to 0.
 *
 * @param count The number of elements to allocate memory for.
 * @param size The size of each element.
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */
void	*mem_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = p(ft_calloc(count, size));
	return (ptr);
}

/**
 * Frees the memory allocated for a dynamically allocated array of strings.
 * 
 * @param array The array of strings to be freed.
 */
void	mem_free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 * @brief Copies a string array, allocating memory for each element
 * and the array itself.
 * 
 * This function copies the string array `src` by allocating memory 
 * for each element and the array itself.
 * It returns a new string array `dst` that is an exact copy of `src`.
 * 
 * @param src The string array to be copied.
 * @return The copied string array `dst`, or NULL if memory allocation fails.
 */
char	**mem_cpy_array(char **src)
{
	char	**dst;
	int		i;

	dst = mem_calloc(array_len(src) + 1, sizeof(char *));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = p(ft_strdup(src[i]));
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
