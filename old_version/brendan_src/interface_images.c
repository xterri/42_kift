/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 14:45:31 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/23 16:09:26 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void		fill_image_with_colour(t_image *i, int c)
{
	int		x;
	int		y;

	y = -1;
	while (++y < i->h)
	{
		x = -1;
		while (++x < i->w)
			i->pix[(y * i->w) + x] = c;
	}
}

t_image		*new_image(t_interface *i, int width, int height)
{
	t_image		*image;

	if (!(image = (t_image *)malloc(sizeof(t_image))))
		return (ft_putnull("Failed to get new_image"));
	image->img = mlx_new_image(i->mlx, width, height);
	image->pix = (int *)mlx_get_data_addr(image->img,
			&image->bpp, &image->w, &image->endian);
	image->w /= 4;
	image->h = height;
	return (image);
}

t_image		*new_xpm_image(t_interface *i, char *image_address)
{
	t_image	*image;

	if (!(image = (t_image *)ft_memalloc(sizeof(t_image))))
		return (ft_putnull("Failed to malloc space for bg"));
	image->img = mlx_xpm_file_to_image(i->mlx, image_address, &image->w, &image->h);
	return (image);
}

t_scrollbar	*get_scrollbar(t_interface *i)
{
	t_scrollbar	*sb;

	if (!(sb = (t_scrollbar *)ft_memalloc(sizeof(t_scrollbar))))
		return (ft_putnull("Failed to malloc space for sb"));
	sb->size = TXTBX_END_H - TXTBX_START_H;
	sb->top_start = TXTBX_START_H;
	sb->bg = new_image(i, 40, sb->size + 5);
	sb->clickything = new_image(i, 30, sb->size + 5);
	fill_image_with_colour(sb->bg, 0x444444);
	fill_image_with_colour(sb->clickything, 0xAAAAAA);
	return (sb);
}

void		free_all_images(t_interface *i)
{
	mlx_destroy_image(i->mlx, i->sb->bg->img);
	mlx_destroy_image(i->mlx, i->sb->clickything->img);
	free(i->sb->bg);
	free(i->sb->clickything);
	free(i->sb);
	mlx_destroy_image(i->mlx, i->bg->img);
	free(i->bg);
}
