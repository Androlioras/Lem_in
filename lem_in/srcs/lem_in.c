/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:31:49 by pribault          #+#    #+#             */
/*   Updated: 2017/02/16 21:16:00 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lst_find(t_list *list, void *room)
{
	while (list)
	{
		if (list->content == room)
			return (1);
		list = list->next;
	}
	return (0);
}

void	lst_del(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void	print_list(t_list *list)
{
	t_room	*room;

	while (list)
	{
		room = (t_room*)list->content;
		ft_printf("[%s:%d]->", room->name, room->ants);
		list = list->next;
	}
	ft_printf("NULL\n");
}

void	print_ant(t_ant *ant)
{
	ft_printf("ants: %u\n", ant->n_ants);
	if (ant->start)
		ft_printf("start: %s\n", ant->start->name);
	else
		ft_printf("no start\n");
	print_list(ant->list);
	if (ant->end)
		ft_printf("end: %s\n", ant->end->name);
	else
		ft_printf("no end\n");
}

int		main(void)
{
	t_ant	ant;

	init_struct(&ant);
	algo(&ant);
	del_struct(&ant);
	return (0);
}
