/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:22:34 by tpicoule          #+#    #+#             */
/*   Updated: 2023/03/10 09:24:11 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;

}	t_node;

typedef struct s_dblist
{
	int				length;
	struct s_node	*tail;
	struct s_node	*head;
}	t_dblist;

t_dblist	*dlist_new(void);
t_dblist	*dlist_add(t_dblist *list, int value);
t_dblist	*dlist_add_end(t_dblist *list, int value);
t_dblist	*ft_dlist_insert(t_dblist *pile, int value, int position);
t_dblist	*dlist_supp_first(t_dblist *pilea);
t_dblist	*dlist_supp_end(t_dblist *pilea);
void		dlist_free(t_dblist **list);
void		ft_swap_a(t_node *a, t_node *b);
void		ft_rotate_b(t_dblist *pilea);
void		ft_rotate_a(t_dblist *pilea);

#endif