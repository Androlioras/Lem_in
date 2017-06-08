/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_converts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:42:50 by pribault          #+#    #+#             */
/*   Updated: 2017/02/08 16:28:30 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsmlx.h"

t_pixel	smlx_mix_color(t_pixel a, t_uint b)
{
	double	r;
	t_pixel	i;

	i = a;
	r = 1 - (a.c & 0xFF000000) / (255 * 0x1000000);
	i.c = (t_uint)(r * (a.c & 0xFF000000) + (1.0 - r) * (b & 0xFF000000));
	i.c = i.c & 0xFF000000;
	i.c += (t_uint)(r * (a.c & 0xFF0000) + (1.0 - r) * (b & 0xFF0000));
	i.c = i.c & 0xFFFF0000;
	i.c += (t_uint)(r * (a.c & 0xFF00) + (1.0 - r) * (b & 0xFF00));
	i.c = i.c & 0xFFFFFF00;
	i.c += (t_uint)(r * (a.c & 0xFF) + (1.0 - r) * (b & 0xFF));
	return (i);
}

double	smlx_deg_to_rad(int deg)
{
	return (deg * 2 * PI / 360);
}

int		smlx_rad_to_deg(double rad)
{
	return (rad * 360 / (2 * PI));
}

t_pixel	smlx_translate(t_pixel p, t_point v)
{
	p.x -= v.x;
	p.y -= v.y;
	return (p);
}
