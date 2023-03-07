/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:10:12 by tpicoule          #+#    #+#             */
/*   Updated: 2023/03/07 16:47:08 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* t_dblist	*ft_swap_a(t_dblist *pilea)
{
	int				value;
	int				i;
	int				tmp;
	struct s_node	*new;

	i = 1;
	if (pilea != NULL)
	{	
	}
	return (pilea);
} */

void	dlist_free(t_dblist **list)
{
	struct s_node	*tmp;
	struct s_node	*del;

	if (*list != NULL)
	{
		tmp = (*list)->first;
		while (tmp != NULL)
		{
			del = tmp;
			tmp = tmp->next;
			free(del);
		}
		free(*list);
		*list = NULL;
	}
}

t_dblist	*ft_dlist_insert(t_dblist *pile, int value, int position)
{
	struct s_node	*tmp;
	struct s_node	*new;
	int				i;

	i = 1;
	if (pile != NULL)
	{
		tmp = pile->first;
		while (tmp != NULL && i <= position)
		{
			if (position == i)
			{
				if (tmp->next == NULL)
					pile = dlist_add(pile, value);
				else if (tmp->prev == NULL)
					pile = dlist_add_end(pile, value);
				else
				{
					new = malloc(sizeof * new);
					if (new != NULL)
					{
						new->value = value;
						tmp->next->prev = new;
						tmp->prev->next = new;
						new->prev = tmp->prev;
						new->next = tmp;
						pile->length++;
					}
				}
			}
			else
				tmp = tmp->next;
			i++;
		}
	}
	return (pile);
}

void	ft_swap_a(t_node *a, t_node *b)
{
	int	tmp;

	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}
/* 
int main(void)
{
	t_node *a = (t_node *) malloc(sizeof(t_node));
	t_node *b = (t_node *) malloc(sizeof(t_node));

	b->value = 1;
	a->value = 4;
	printf("before\nb=%d\n", b->value);
	printf("a=%d\n", a->value);
	ft_swap_a(a, b);
	printf("after\nb=%d\n", b->value);
	printf("a=%d\n", a->value);
	return (0);
} */
