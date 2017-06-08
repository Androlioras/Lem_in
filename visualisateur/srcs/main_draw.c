/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:54:52 by pribault          #+#    #+#             */
/*   Updated: 2017/02/16 15:35:05 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	move_ant(t_env *env, int ant, char *room)
{
	t_list	*list;
	t_room	*from;
	t_room	*to;

	if (ant > env->anthill.n_ants)
		del_and_exit_3(env, 1);
	from = env->anthill.ants[ant - 1];
	list = env->anthill.list;
	to = NULL;
	while (list && !to)
	{
		if (!ft_strcmp(((t_room*)(list->content))->name, room))
			to = (t_room*)(list->content);
		list = list->next;
	}
	if (!to)
		del_and_exit_3(env, 1);
	from->ants--;
	to->ants++;
	env->anthill.ants[ant - 1] = to;
}

int		get_infos(t_env *env, char *move, int i)
{
	char	*room;
	long	ant;
	int		j;

	ant = 0;
	if (move[i] == 'L')
		i++;
	while (move[i] && move[i] >= '0' && move[i] <= '9')
	{
		ant = ant * 10 + move[i++] - '0';
		if (ant > 2147483647)
			del_and_exit_3(env, 1);
	}
	if (move[i] == '-')
		i++;
	j = i;
	while (move[j] && move[j] != ' ')
		j++;
	if (!(room = ft_strndup(move + i, j - i)))
		del_and_exit_3(env, 1);
	move_ant(env, (int)ant, room);
	free(room);
	return (j);
}

void	next_move(t_env *env)
{
	char	*move;
	int		i;

	move = NULL;
	if (ft_get_next_line(0, &move) == 1)
	{
		i = 0;
		while (move[i])
		{
			i = get_infos(env, move, i);
			if (move[i] == ' ')
				i++;
		}
	}
	if (move)
		free(move);
}

void	print_strings(t_env *env, int fps)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = ft_itoa(fps);
	s2 = ft_strjoin("fps: ", s1);
	mlx_string_put(env->win.mlx, env->win.win, 10, 25, 0xFFFFFF, s1);
	free(s1);
	free(s2);
	s1 = ft_itoa(env->anthill.end->ants);
	s2 = ft_itoa(env->anthill.n_ants);
	s3 = ft_strjoin("end: ", s1);
	free(s1);
	s1 = ft_strjoin(s3, "/");
	free(s3);
	s3 = ft_strjoin(s1, s2);
	mlx_string_put(env->win.mlx, env->win.win, 10, 5, 0xFFFFFF, s3);
	free(s1);
	free(s2);
	free(s3);
}

int		hook_loop(t_env *e)
{
	static time_t		prev;
	time_t				t;
	static int			frames;
	static int			fps = 0;

	t = time(NULL);
	if (t > prev)
	{
		fps = frames / (t - prev);
		frames = 0;
		prev = t;
	}
	frames++;
	keys(e);
	smlx_clear_image(e->img.img);
	draw_ants(e);
	mlx_put_image_to_window(e->win.mlx, e->win.win, e->background->img, 0, 0);
	mlx_put_image_to_window(e->win.mlx, e->win.win, e->img.img->img, 0, 0);
	print_strings(e, fps);
	return (1);
}
