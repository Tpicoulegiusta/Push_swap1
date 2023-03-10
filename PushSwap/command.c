/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:10:12 by tpicoule          #+#    #+#             */
/*   Updated: 2023/03/10 09:24:20 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlist_free(t_dblist **list)
{
	struct s_node	*tmp;
	struct s_node	*del;

	if (*list != NULL)
	{
		tmp = (*list)->head;
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
	new = pileb->head;
	pileb->head->next->prev = NULL;
	new->next = pilea->head;
	pilea->head->prev = new;
}

t_dblist	*dlist_supp_first(t_dblist *pilea)
{
	struct s_node	*tmp;

	if (!pilea)
		return (NULL);
	if (pilea->head == pilea->tail)
		return (free (pilea), NULL);
	tmp = pilea->head;
	pilea->head = pilea->head->next;
	return (free(tmp), pilea);
}

void	ft_rotate_a(t_dblist *pilea)
{
	if (!pilea)
		return ;
	pilea = dlist_add_end(pilea, pilea->head->value);
	pilea = dlist_supp_first(pilea);
	write(1, "ra\n", 3);
}

t_dblist	*dlist_supp_end(t_dblist *pilea)
{
	struct s_node	*tmp;

	if (!pilea)
		return (NULL);
	if (pilea->head == pilea->tail)
		return (free (pilea), NULL);
	tmp = pilea->tail;
	pilea->tail = pilea->tail->next;
	return (free(tmp), pilea);
}

void	ft_rotate_b(t_dblist *pilea)
{
	if (!pilea)
		return ;
	pilea = dlist_add_end(pilea, pilea->head->value);
	pilea = dlist_supp_end(pilea);
	write(1, "rb\n", 3);
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
