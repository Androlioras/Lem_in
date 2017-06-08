/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 21:12:02 by pribault          #+#    #+#             */
/*   Updated: 2017/02/16 22:11:20 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

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
	ant->list = NULL;
	ant->start = NULL;
	ant->end = NULL;
	free(ant->ants);
}

void	del_and_exit_2(t_ant *ant, int state)
{
	write(1, "ERROR\n", 6);
	del_struct(ant);
	exit(state);
}

void	del_and_exit_3(t_env *env, int state)
{
	if (state == 1)
		write(1, "ERROR\n", 6);
	del_struct(&env->anthill);
	smlx_destroy_image(&env->win, &env->back.img);
	smlx_destroy_image(&env->win, &env->title.img);
	smlx_destroy_image(&env->win, &env->img.img);
	smlx_destroy_image(&env->win, &env->room);
	smlx_destroy_image(&env->win, &env->pipe);
	smlx_destroy_image(&env->win, &env->background);
	smlx_destroy_image(&env->win, &env->ant_1);
	smlx_destroy_image(&env->win, &env->ant_2);
	smlx_destroy_image(&env->win, &env->unicorn);
	smlx_destroy_image(&env->win, &env->salameche);
	smlx_destroy_window(&env->win);
	exit(state);
}
