/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:50:46 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/19 20:05:21 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

t_image		*new_image(t_interface *i, int width, int height)
{
	t_image		*image;

	image = (t_image *)malloc(sizeof(t_image));
	image->img = mlx_new_image(i->mlx, width, height);
	image->pix = (int *)mlx_get_data_addr(image->img,
			&image->bpp, &image->w, &image->endian);
	image->w /= 4;
	image->h = height;
	return (image);
}

t_image		*get_background(t_interface *i)
{
	t_image	*bg;

	if (!(bg = (t_image *)ft_memalloc(sizeof(t_image))))
		return (ft_putnull("Failed to malloc space for bg"));
	bg->img = mlx_xpm_file_to_image(i->mlx, "images/bg.xpm", &bg->w, &bg->h);
	return (bg);
}
