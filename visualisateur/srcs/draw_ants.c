/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:57:55 by pribault          #+#    #+#             */
/*   Updated: 2017/02/16 15:34:41 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		set_zoom(t_env *env, t_args *args)
{
	int		t;

	t = (env->anthill.x_max - env->anthill.x_min + 1);
	if (env->anthill.x_max - env->anthill.x_min + 1 != 0)
		args->z = ((double)env->img.img->h / env->ant->h) / t;
	args->z *= (double)2 / 3;
}

void		calculate_args(t_env *env, t_args *args, t_args *args2)
{
	args->vec.x -= args2->z * env->room->w / 2;
	args->vec.y -= args2->z * env->room->w / 2;
	args->vec.x *= env->back.args.z;
	args->vec.y *= env->back.args.z;
	args->vec.x += (env->room->w * args2->z - env->ant->w * args->z) / 2;
	args->vec.y += (env->room->h * args2->z - env->ant->h * args->z) / 2;
}

void		draw_ants(t_env *env)
{
	t_room	*room;
	t_args	args;
	t_args	args2;
	int		i;

	i = 0;
	args = smlx_create_arg(env->rotation, 0, 0, 1);
	set_zoom(env, &args);
	set_zoom_2(env, &args2);
	while (i < env->anthill.n_ants)
	{
		room = env->anthill.ants[i++];
		if (i == 1 || room != env->anthill.ants[i - 2])
		{
			set_coords(env, &args, room->x, room->y);
			calculate_args(env, &args, &args2);
			smlx_put_img_to_img(env->ant, env->img.img, &args);
		}
		if (room == env->anthill.start)
		{
			smlx_destroy_matrix(args.mat);
			return ;
		}
	}
	smlx_destroy_matrix(args.mat);
}
