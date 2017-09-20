/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:50:46 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/19 14:51:55 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

t_image		*new_image(t_interface *i, int width, int height)
{
	t_image		*image;

	image = (t_image *)malloc(sizeof(t_image));
	image->img = mlx_new_image(rt->mlx, width, height);
	image->pix = (int *)mlx_get_data_addr(image->img,
			&image->bpp, &image->w, &image->endian);
	image->w /= 4;
	image->h = height;
	return (image);
}
