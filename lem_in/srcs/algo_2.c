/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:06:17 by pribault          #+#    #+#             */
/*   Updated: 2017/02/16 21:10:25 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lst_add(t_list **head, t_list *new)
{
	t_list	*list;

	if (*head == NULL)
		*head = new;
	else
	{
		list = *head;
		while (list->next)
		{
			list = list->next;
		}
		list->next = new;
	}
}

void	move_ant(t_ant *ant, t_room *from, t_room *to, int i)
{
	from->ants--;
	to->ants++;
	ant->ants[i] = to;
	ant->first = 0;
	ft_printf("L%d-%s ", i + 1, to->name);
}
