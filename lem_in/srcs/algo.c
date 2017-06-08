/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 03:01:08 by pribault          #+#    #+#             */
/*   Updated: 2017/02/16 21:16:37 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_room(t_room *room)
{
	t_list	*list;
	t_room	*r;

	list = room->rooms;
	if (room->d == -1)
		return (0);
	while (list)
	{
		r = (t_room*)list->content;
		if (r->d == -1 || ft_abs(room->d - r->d) > 1)
			return (0);
		list = list->next;
	}
	return (1);
}

void	set_distance(t_room *room, t_list **rooms, int state)
{
	t_list	*list;
	t_room	*r;

	if (check_room(room))
		return ;
	if (state == END)
		room->d = 0;
	ft_lstadd(rooms, add_list_room(room));
	list = room->rooms;
	while (list)
	{
		r = (t_room*)list->content;
		if (r->d != -1 && (room->d == -1 || r->d < room->d))
			room->d = r->d + 1;
		list = list->next;
	}
	list = room->rooms;
	while (list)
	{
		r = (t_room*)list->content;
		if (r->d == -1 || r->d > room->d)
			set_distance((t_room*)list->content, rooms, 0);
		list = list->next;
	}
}

int		best_path(t_ant *ant, t_room *room, t_room *room_to)
{
	t_list	*list;
	t_room	*r;

	list = room->rooms;
	if (room_to->ants && ant->end != room_to)
		return (0);
	while (list)
	{
		r = (t_room*)list->content;
		if (r->d < room_to->d && r != room_to && (r == ant->end || !r->ants))
			return (0);
		list = list->next;
	}
	if (room_to->d <= room->d)
		return (1);
	return (0);
}

void	move_ants(t_ant *ant, int i)
{
	t_list	*list;
	t_room	*room;
	t_room	*r;

	if (i >= ant->n_ants)
		return ;
	room = (t_room*)ant->ants[i];
	list = room->rooms;
	ant->first = 1;
	while ((t_room*)ant->ants[i] == room && list)
	{
		r = (t_room*)list->content;
		if (best_path(ant, room, r) && (t_room*)ant->ants[i] != ant->end)
			move_ant(ant, room, r, i);
		list = list->next;
	}
	list = room->rooms;
	move_ants(ant, i + 1);
}

void	algo(t_ant *ant)
{
	t_list	*list;
	t_list	*prev;
	t_list	*rooms;

	rooms = NULL;
	if (!ant || !ant->start || !ant->end)
		return ;
	set_distance(ant->end, &rooms, END);
	if (ant->start->d == -1)
		del_and_exit(ant, 1);
	list = ant->write;
	while (list)
	{
		prev = list;
		list = list->next;
		ft_putendl((char*)prev->content);
	}
	ft_putchar('\n');
	lst_del(rooms);
	while (ant->end->ants != ant->n_ants)
	{
		move_ants(ant, 0);
		ft_putchar('\n');
	}
}
