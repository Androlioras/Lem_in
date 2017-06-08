/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:32:43 by pribault          #+#    #+#             */
/*   Updated: 2017/02/16 16:07:38 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "ft_printf.h"
# include <libsmlx.h>
# include <time.h>

/*
**	macros
*/

# define START	1
# define END	2
# define ANT	-3
# define WIN	-4
# define FLAGS	-5

/*
**	macros keys
*/

# define ESCAPE	10

/*
**	structures fourmiliere
*/

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	int					ants;
	int					pipes;
	int					d;
	t_list				*rooms;
}						t_room;

typedef struct			s_ant
{
	int					x_min;
	int					y_min;
	int					x_max;
	int					y_max;
	int					n_ants;
	t_room				**ants;
	t_list				*list;
	t_room				*start;
	t_room				*end;
}						t_ant;

/*
**	structures graphiques
*/

typedef struct			s_env
{
	t_ant				anthill;
	t_win				win;
	t_obj				back;
	t_obj				title;
	t_obj				img;
	t_image				*ant;
	t_image				*ant_1;
	t_image				*ant_2;
	t_image				*unicorn;
	t_image				*salameche;
	t_image				*room;
	t_image				*pipe;
	t_image				*background;
	t_uint				color;
	int					rotate;
	int					rotation;
	int					next_step;
}						t_env;

/*
**	prototypes
*/

/*
**	main functions
*/

void					init_struct(t_ant *ant);
void					del_struct(t_ant *ant);
void					del_and_exit(t_list *list, int state);
void					del_and_exit_2(t_ant *ant, int state);
void					del_and_exit_3(t_env *env, int state);

void					load_buttons(t_env *env);
void					keys(t_env *env);

void					set_zoom_2(t_env *env, t_args *args);
void					set_coords(t_env *e, t_args *a, double x, double y);
void					next_move(t_env *env);

/*
**	ants functions
*/

void					set_ants(t_ant *ant, char *line, int *state);
void					add_room(t_ant *ant, char *line, int *state);
void					add_pipe(t_ant *ant, char *line);
void					del_room(void *room, size_t size);

/*
**	list functions
*/

t_list					*lst_new(void *content);
void					lst_del(t_list *list);

/*
**	graphic functions
*/

int						hook_loop(t_env *env);

void					draw_anthill(t_env *env);
void					draw_ants(t_env *env);

#endif
