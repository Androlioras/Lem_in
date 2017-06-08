/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_pixel_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:41:13 by pribault          #+#    #+#             */
/*   Updated: 2017/02/04 12:36:13 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsmlx.h"

void	smlx_pixel_put(t_image *img, t_pixel p)
{
	if (!img || !img->l)
		return ;
	if (p.x < 0 || p.x >= img->w || p.y < 0 || p.y >= img->h)
		return ;
	img->l[p.y * img->size_l / 4 + p.x * img->bits / 32] = p.c;
}
