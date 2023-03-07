/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:39:05 by tpicoule          #+#    #+#             */
/*   Updated: 2023/03/06 15:15:57 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dblist	*dlist_new(void)
{
	t_dblist	*new;

	new = malloc(sizeof * new);
	if (new != NULL)
	{
		new->length = 0;
		new->first = NULL;
		new->last = NULL;
	}
	return (new);
}

t_dblist	*dlist_add(t_dblist *list, int value)
{
	struct s_node	*new;

	if (list != NULL)
	{
		new = malloc(sizeof * new);
		if (new != NULL)
		{
			new->value = 0;
			new->next = NULL;
			if (list->last == NULL)
			{
				new->prev = NULL;
				list->first = new;
				list->last = new;
			}
			else
			{
				list->last->next = new;
				new->prev = list->last;
				list->last = new;
			}
			list->length++;
		}
	}
	return (list);
}

t_dblist	*dlist_add_end(t_dblist *list, int value)
{
	struct s_node	*new;

	if (list != NULL)
	{
		new = malloc(sizeof * new);
		if (new != NULL)
		{
			new->value = 0;
			new->prev = NULL;
			if (list->last == NULL)
			{
				new->next = NULL;
				list->first = new;
				list->last = new;
			}
			else
			{
				list->first->prev = new;
				new->next = list->first;
				list->first = new;
			}
			list->length++;
		}
	}
	return (list);
}
