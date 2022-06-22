/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:20:33 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/06/22 14:24:13 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool	parse_link(t_data *data, t_array *rooms, char *link)
{
	char	*room;
	int		first;
	int		second;

	room = link;
	while (*room != '-')
		room++;
	*room = '\0';
	room++;
	first = binary_search(rooms->array, link, 0, rooms->nb_of_elements - 1);
	second = binary_search(rooms->array, room, 0, rooms->nb_of_elements - 1);
	*(room - 1) = '-';
	if (first < 0 || second < 0 || first == second
		|| find_node(data->rooms[first].links, second)
		|| find_node(data->rooms[second].links, first))
		return (false);
	if (!add_to_start(&data->rooms[first].links, second)
		|| !add_to_start(&data->rooms[second].links, first))
		return (false);
	return (true);
}

bool	parse_links(t_input *input, t_data *data)
{
	size_t	i;

	i = 0;
	while (i < input->links.nb_of_elements)
	{
		if (!parse_link(data, &input->rooms, input->links.array[i++]))
			return (false);
	}
	return (true);
}