/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:02:50 by pribault          #+#    #+#             */
/*   Updated: 2017/02/16 16:12:47 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	keys(t_env *env)
{
	if (env->win.keys.tab[53])
		del_and_exit_3(env, 0);
	if (env->win.keys.tab[49])
		next_move(env);
	if (env->win.keys.tab[123])
		env->rotate++;
	if (env->win.keys.tab[124])
		env->rotate--;
	if (env->win.keys.tab[76])
	{
		if (env->next_step == 0)
			next_move(env);
		env->next_step = (env->next_step == 0) ? 1 : env->next_step;
	}
	else
		env->next_step = 0;
	if (env->win.keys.tab[83])
		env->ant = env->ant_1;
	if (env->win.keys.tab[84])
		env->ant = env->ant_2;
	if (env->win.keys.tab[85])
		env->ant = env->unicorn;
	if (env->win.keys.tab[86])
		env->ant = env->salameche;
	env->rotation += env->rotate;
}
