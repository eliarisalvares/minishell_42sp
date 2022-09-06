/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.b>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:23:12 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/30 01:24:16 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * A hash_function table is a data structure that stores data in a way that
 * allows fast lookup. Ideally, it should be possible to find the object we are
 * looking for in constant time (O(1)). Essentially, a hash_function table is
 * an array with a hash_function function that maps a key to an index in an
 * array. In other words, a function that takes an input and returns an
 * integer that represents the location in which the input is stored in the
 * array. There are many different hash_function functions, but the most common
 * one is called the djb2 hash_function function. The djb2 hash_function
 * function is a simple hash_function function and is the one chosen for
 * implementation in this project. The hash_function function must always
 * return a value between 0 and the size of the table - 1. It is consistent,
 * meaning that it will always return the same value for the same input.
 * @brief The djb2 hash_function function is a simple hash_function function
and is the one chosen for implementation in this project.
 * @seemore: https://theartincode.stanis.me/006-djb2/
 * @param key The key to be hashed.
 * @param size The size of the hash_function table.
 * @return The index in the hash_function table where the key should be stored.
*/

unsigned long int	hash_function(char *key, unsigned int size)
{
	unsigned long int	hash_function;
	unsigned int		index;

	hash_function = 5381;
	index = 0;
	while (key && key[index])
	{
		hash_function = ((hash_function << 5) + hash_function) + key[index];
		index++;
	}
	return (hash_function % size);
}
