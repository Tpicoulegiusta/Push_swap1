/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:10:12 by tpicoule          #+#    #+#             */
/*   Updated: 2023/03/08 11:09:54 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_swap_a(t_node *a, t_node *b)
{
	int	tmp;

	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

void	ft_push_a(t_dblist *pilea, t_dblist *pileb)
{
	struct s_node	*new;

	if (!pileb || !pilea)
		return ;
	new = pileb->last;
	pileb->last->next->prev = NULL;
	new->next = pilea->last;
	pilea->last->prev = new;
}

void	ft_rotate_a(t_dblist *pilea)
{
	struct s_node	*tmp2;
	struct s_node	*tmp;
	struct s_node	*tmp3;

	if (!pilea)
		return ;
	tmp = pilea->last;
	tmp2 = pilea->first;
	while (pilea)
	{
		pilea->last->prev->prev->value = pilea->last->prev->value;
	}
	tmp->prev = NULL;
	tmp->next = pilea->first->next;
	tmp2->next = NULL;
	tmp2->prev = pilea->last->prev;
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
