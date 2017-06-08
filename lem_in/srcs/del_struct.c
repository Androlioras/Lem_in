/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 21:12:02 by pribault          #+#    #+#             */
/*   Updated: 2017/02/16 20:57:05 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_struct(t_ant *ant)
{
	t_list	*list;
	t_list	*prev;
	t_room	*room;

	list = ant->list;
	while (list)
	{
		room = (t_room*)list->content;
		prev = list;
		list = list->next;
		del_room(room, sizeof(t_room));
		free(prev);
	}
	list = ant->write;
	while (list)
	{
		prev = list;
		list = list->next;
		free(prev->content);
		free(prev);
	}
	if (ant->ants)
		free(ant->ants);
}

void	del_and_exit(t_ant *ant, int state)
{
	write(1, "ERROR\n", 6);
	del_struct(ant);
	exit(state);
}
