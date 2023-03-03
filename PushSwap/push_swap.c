/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:46:56 by tpicoule          #+#    #+#             */
/*   Updated: 2023/03/03 12:31:19 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	t_dblist	*pilea;
	t_dblist	*pileb;

	i = 0;
	pilea = dlist_new();
	pileb = dlist_new();
	//ON CREER PILE A
	while (i < argc - 1)
	{
		dlist_add(pilea, i);
		i++;
	}
	//write(1, "caca\n", 5);
	//printf("%d", i);

}
