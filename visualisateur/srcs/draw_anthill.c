/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_anthill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:34:55 by pribault          #+#    #+#             */
/*   Updated: 2017/02/16 11:40:02 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		set_zoom_2(t_env *env, t_args *args)
{
	int		t;

	t = (env->anthill.x_max - env->anthill.x_min + 1);
	if (env->anthill.x_max - env->anthill.x_min + 1 != 0)
		args->z = ((double)env->back.img->h / env->room->h) / t;
}

void		set_coords(t_env *env, t_args *args, double x, double y)
{
	static double	a_1 = -1;
	static double	a_2;
	static int		b_1;
	static int		b_2;
	long double		temp;

	if (a_1 < 0)
	{
		temp = env->back.img->w - env->room->w * args->z;
		a_1 = temp / (env->anthill.x_max - env->anthill.x_min);
		temp = env->back.img->h - env->room->h * args->z;
		temp = temp - env->title.img->h * env->title.args.z;
		a_2 = temp / (env->anthill.y_max - env->anthill.y_min);
		b_1 = env->back.img->w - a_1 * env->anthill.x_max;
		b_2 = env->back.img->h - a_2 * env->anthill.y_max;
	}
	args->vec.x = x * a_1 + b_1;
	args->vec.y = y * a_2 + b_2;
}

void		draw_pipes(t_env *env, t_room *room)
{
	t_list	*list;
	t_args	p_1;
	t_args	p_2;
	t_room	*to;
	t_pixel	p[2];

	list = room->rooms;
	while (list)
	{
		to = (t_room*)list->content;
		set_coords(env, &p_1, room->x, room->y);
		set_coords(env, &p_2, to->x, to->y);
		p[0] = smlx_create_pixel(p_1.vec.x, p_1.vec.y, env->color);
		p[1] = smlx_create_pixel(p_2.vec.x, p_2.vec.y, env->color);
		smlx_draw_line(env->back.img, p[0], p[1]);
		list = list->next;
	}
}

void		draw_anthill(t_env *env)
{
	t_list	*list;
	t_room	*room;
	t_args	args;

	env->anthill.x_max += 1;
	env->anthill.y_max += 1;
	list = env->anthill.list;
	args = smlx_create_arg(0, 0, 0, 1);
	set_zoom_2(env, &args);
	while (list)
	{
		room = (t_room*)list->content;
		set_coords(env, &args, room->x, room->y);
		args.vec.x -= args.z * env->room->w / 2;
		args.vec.y -= args.z * env->room->w / 2;
		smlx_put_img_to_img(env->room, env->back.img, &args);
		draw_pipes(env, room);
		list = list->next;
	}
	smlx_destroy_matrix(args.mat);
}
