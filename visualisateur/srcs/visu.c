/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:32:54 by pribault          #+#    #+#             */
/*   Updated: 2017/02/17 11:48:11 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		lst_del(t_list *list)
{
	t_list	*prev;

	while (list)
	{
		prev = list;
		list = list->next;
		free(prev);
	}
}

t_list		*lst_new(void *content)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(t_list));
	list->content = content;
	list->content_size = 42;
	list->next = NULL;
	return (list);
}

static void	repos_title(t_obj *title, t_obj *screen)
{
	int		r;

	r = (screen->img->w - title->img->w * title->args.z) / 2;
	title->args.vec.x = r;
}

static void	load_textures(t_env *env, int size)
{
	env->img.img = smlx_new_image(&(env->win), env->win.w, env->win.h);
	env->background = smlx_new_image(&(env->win), env->win.w, env->win.h);
	env->back.img = smlx_new_image_xpm(&(env->win), "textures/ground.xpm");
	env->title.img = smlx_new_image_xpm(&(env->win), "textures/title.xpm");
	env->room = smlx_new_image_xpm(&(env->win), "textures/room.xpm");
	env->pipe = smlx_new_image_xpm(&(env->win), "textures/pipe.xpm");
	env->ant_1 = smlx_new_image_xpm(&(env->win), "textures/ant.xpm");
	env->ant_2 = smlx_new_image_xpm(&(env->win), "textures/ant_2.xpm");
	env->unicorn = smlx_new_image_xpm(&(env->win), "textures/unicorn_2.xpm");
	env->salameche = smlx_new_image_xpm(&(env->win), "textures/salameche.xpm");
	env->ant = env->ant_1;
	if (!env->img.img || !env->background || !env->back.img || !env->title.img
	|| !env->ant || !env->room || !env->pipe || !env->ant_1 || !env->ant_2
	|| !env->unicorn || !env->salameche)
		del_and_exit_3(env, 1);
	env->color = env->room->l[env->room->w / 2];
	env->img.args = smlx_create_arg(0, 0, 0, 1);
	env->back.args = smlx_create_arg(0, 0, 0, (double)size / env->back.img->w);
	env->title.args = smlx_create_arg(0, 0, 0, 1.25);
	env->rotate = 0;
	env->rotation = 0;
	env->next_step = 0;
}

int			main(int argc, char **argv)
{
	t_env	env;
	int		size;

	size = (argc == 2) ? ft_atoi(argv[1]) : 1024;
	init_struct(&env.anthill);
	smlx_set_flags(&env.win, SMLX_ROTATION | SMLX_C_SLOPE | SMLX_MOTION);
	smlx_init(&env.win, size, size, "visu");
	load_textures(&env, size);
	repos_title(&env.title, &env.back);
	smlx_put_img_to_img(env.title.img, env.back.img, &env.title.args);
	draw_anthill(&env);
	if (!env.anthill.n_ants || !env.anthill.start || !env.anthill.end)
		return (0);
	smlx_put_img_to_img(env.back.img, env.background, &env.back.args);
	smlx_key_hook(&(env.win));
	mlx_loop_hook(env.win.mlx, &hook_loop, &env);
	mlx_loop(env.win.mlx);
	return (0);
}
