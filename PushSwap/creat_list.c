/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:39:05 by tpicoule          #+#    #+#             */
/*   Updated: 2023/03/09 12:33:46 by tpicoule         ###   ########.fr       */
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
		new->head = NULL;
		new->tail = NULL;
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
			if (list->tail == NULL)
			{
				new->prev = NULL;
				list->head = new;
				list->tail = new;
			}
			else
			{
				list->tail->next = new;
				new->prev = list->tail;
				list->tail = new;
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
			if (list->tail == NULL)
			{
				new->next = NULL;
				list->head = new;
				list->tail = new;
			}
			else
			{
				list->head->prev = new;
				new->next = list->head;
				list->head = new;
			}
			list->length++;
		}
	}
	return (list);
}
