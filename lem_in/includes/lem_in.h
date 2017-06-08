/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:28:44 by pribault          #+#    #+#             */
/*   Updated: 2017/02/16 21:10:03 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_printf.h"

/*
**	macros
*/

# define START	1
# define END	2

/*
**	structures
*/

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				ants;
	int				pipes;
	int				d;
	t_list			*rooms;
}					t_room;

typedef struct		s_ant
{
	int				first;
	int				n_ants;
	t_room			**ants;
	t_list			*list;
	t_room			*start;
	t_room			*end;
	t_list			*write;
}					t_ant;

/*
**	prototypes
*/

void				algo(t_ant *ant);

void				move_ant(t_ant *ant, t_room *from, t_room *to, int i);

void				init_struct(t_ant *ant);

void				del_struct(t_ant *ant);
void				del_and_exit(t_ant *ant, int state);

void				del_room(void *room, size_t size);

void				set_ants(t_ant *ant, char *line, int *state);
void				add_room(t_ant *ant, char *line, int *state);
void				add_pipe(t_ant *ant, char *line);

t_list				*add_list_room(t_room *room);

void				print_ant(t_ant *ant);
void				print_list(t_list *list);
void				lst_add(t_list **head, t_list *new);
int					lst_find(t_list *list, void *room);
void				lst_del(t_list *list);

#endif
