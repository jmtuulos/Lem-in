/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:35:43 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/06/21 15:51:27 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

t_list	*new_node(int index)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->room = index;
	new->next = NULL;
	return (new);
}

bool	add_to_start(t_list **a, int index)
{
	t_list	*tmp;

	if (!a || !*a)
		(*a) = new_node(index);
	else
	{
		tmp = new_node(index);
		tmp->next = *a;
		*a = tmp;
	}
	if (!(*a))
		return (false);
	return (true);
}
