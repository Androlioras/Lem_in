/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 03:18:56 by pribault          #+#    #+#             */
/*   Updated: 2017/02/16 19:43:21 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	del_room(void *room, size_t size)
{
	t_list	*prev;
	t_list	*list;

	size++;
	list = ((t_room*)room)->rooms;
	while (list)
	{
		prev = list;
		list = list->next;
		free(prev);
	}
	free(((t_room*)room)->name);
	free(((t_room*)room));
}

size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}

int		is_a_command(char *s, int *state)
{
	if (s[0] && s[0] == '#')
	{
		if (!ft_strcmp(s, "##start"))
			*state += START;
		if (!ft_strcmp(s, "##end"))
			*state += END;
		return (1);
	}
	return (0);
}

void	build_list(t_ant *ant)
{
	char	*line;
	int		state;
	int		words[2];

	state = -2;
	while ((ft_get_next_line(0, &line)) && ft_strcmp("", line))
	{
		if (!is_a_command(line, &state))
		{
			words[0] = ft_count_words(line, ' ');
			words[1] = ft_count_words(line, '-');
			state = (state == 0 && words[0] == 1 && words[1] == 2) ? -1 : state;
			if (state == -2 && words[0] == 1 && words[1] == 1)
				set_ants(ant, line, &state);
			else if (state >= 0 && words[0] == 3)
				add_room(ant, line, &state);
			else if (state == -1 && words[0] == 1 && words[1] == 2)
				add_pipe(ant, line);
			else
				del_and_exit_2(ant, 1);
		}
		free(line);
	}
	free(line);
}

void	init_struct(t_ant *ant)
{
	int		i;

	ant->x_min = 0;
	ant->y_min = 0;
	ant->x_max = 0;
	ant->y_max = 0;
	ant->list = NULL;
	ant->start = NULL;
	ant->end = NULL;
	ant->n_ants = 0;
	build_list(ant);
	if (!ant->end || !ant->start || ant->n_ants < 0)
		del_and_exit_2(ant, 1);
	if (!ant->n_ants)
		return ;
	ant->start->ants = ant->n_ants;
	ant->ants = (t_room**)malloc(sizeof(t_room*) * ant->n_ants);
	i = 0;
	while (i < ant->n_ants)
		ant->ants[i++] = ant->start;
}
