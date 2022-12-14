/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_array_manipulation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:42:39 by jheiskan          #+#    #+#             */
/*   Updated: 2022/08/03 14:59:30 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool	init_struct_array(t_array *new)
{
	new->nb_of_elements = 0;
	new->size = 2;
	new->array = (char **)malloc(sizeof(char *) * new->size);
	if (!new->array)
		return (false);
	return (true);
}

bool	add_element(t_array *array, char *element)
{
	if (array->nb_of_elements >= array->size && !realloc_array(array))
		return (false);
	array->array[array->nb_of_elements] = ft_strdup(element);
	if (!array->array[array->nb_of_elements])
		return (false);
	array->nb_of_elements++;
	return (true);
}

bool	del_structure_array(t_array *array)
{
	if (!array)
		return (true);
	while (array->nb_of_elements-- > 0)
		if (array->array[array->nb_of_elements])
			free(array->array[array->nb_of_elements]);
	free(array->array);
	return (true);
}

void	del_array(char **array, size_t size)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (i < size && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

bool	realloc_array(t_array *array)
{
	char	**new;
	size_t	i;

	i = 0;
	array->size *= 2;
	new = (char **)malloc(sizeof(char *) * array->size);
	if (!new && del_structure_array(array))
		return (false);
	ft_bzero(new, sizeof(new));
	while (array->nb_of_elements > i)
	{
		new[i] = ft_strdup(array->array[i]);
		if (!new[i] && del_structure_array(array))
		{
			del_array(new, array->nb_of_elements);
			return (false);
		}
		i++;
	}
	del_array(array->array, array->nb_of_elements);
	array->array = new;
	return (true);
}
