/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 22:28:11 by pribault          #+#    #+#             */
/*   Updated: 2017/02/16 20:30:23 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_list	*add_list_room(t_room *room)
{
	t_list	*list;

	if (!room)
		return (NULL);
	list = (t_list*)malloc(sizeof(t_list));
	list->content = (void*)room;
	list->content_size = sizeof(t_room);
	list->next = NULL;
	return (list);
}

int		ft_atoi_custom(t_ant *ant, char *str)
{
	int		neg;
	long	number;
	int		i;

	neg = 1;
	number = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		neg = 44 - str[i++];
	while (str[i] < 58 && str[i] > 47)
	{
		number = number * 10 + str[i++] - 48;
		if (number * neg < -2147483648 || number * neg > 2147483647)
			del_and_exit_2(ant, 1);
	}
	if (str[i])
		del_and_exit_2(ant, 1);
	return (number * neg);
}

void	add_room(t_ant *ant, char *line, int *state)
{
	t_room	*new;
	char	**params;

	if (!(new = (t_room*)malloc(sizeof(t_room))) || line[0] == 'L')
		del_and_exit_2(ant, 1);
	params = ft_strsplit(line, ' ');
	if (ft_strchr(params[0], ' ') || ft_strchr(params[0], '-'))
		del_and_exit_2(ant, 1);
	new->name = ft_strdup(params[0]);
	new->ants = 0;
	new->x = ft_atoi_custom(ant, params[1]);
	new->y = ft_atoi_custom(ant, params[2]);
	new->pipes = 0;
	new->rooms = NULL;
	ant->x_min = (!ant->list || new->x < ant->x_min) ? new->x : ant->x_min;
	ant->y_min = (!ant->list || new->y < ant->y_min) ? new->y : ant->y_min;
	ant->x_max = (!ant->list || new->x > ant->x_max) ? new->x : ant->x_max;
	ant->y_max = (!ant->list || new->y > ant->y_max) ? new->y : ant->y_max;
	ft_lstadd(&(ant->list), add_list_room(new));
	if (*state == START || *state == START + END)
		ant->start = new;
	if (*state == END || *state == START + END)
		ant->end = new;
	*state = 0;
	ft_free_array((void**)params, 4);
}

void	add_pipe(t_ant *ant, char *line)
{
	char	**params;
	t_room	*room_a;
	t_room	*room_b;
	t_list	*list;

	room_a = NULL;
	room_b = NULL;
	list = ant->list;
	params = ft_strsplit(line, '-');
	while (list && (!room_a || !room_b))
	{
		if (!ft_strcmp(((t_room*)(list->content))->name, params[0]))
			room_a = list->content;
		if (!ft_strcmp(((t_room*)(list->content))->name, params[1]))
			room_b = list->content;
		list = list->next;
	}
	room_a->pipes++;
	room_b->pipes++;
	ft_lstadd(&(room_a->rooms), add_list_room(room_b));
	ft_lstadd(&(room_b->rooms), add_list_room(room_a));
	ft_free_array((void**)params, 3);
}

void	set_ants(t_ant *ant, char *line, int *state)
{
	ant->n_ants = ft_atoi_custom(ant, line);
	*state = 0;
}
