/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:10:11 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/24 13:55:15 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

static int		map_number(int oldmax, int newmax, int old_number)
{
	int		oldrange;

	oldrange = (oldmax - TXTBX_START_H == 0) ? 1 : (oldmax - TXTBX_START_H);
	return ((((old_number - TXTBX_START_H) * newmax) / oldrange) + 0);
}

static void		scrollbar_display(t_interface *i, int num_hidden)
{
	static int	old_hidden;

	if (old_hidden < num_hidden)
	{
		i->sb->size = (TXTBX_END_H - TXTBX_START_H) * 1 / sqrt(num_hidden);
		if (i->sb->top_start == i->sb->top_end)
			i->sb->top_start = TXTBX_END_H - i->sb->size;
		i->sb->top_end = TXTBX_END_H - i->sb->size;
		mlx_destroy_image(i->mlx, i->sb->clickything->img);
		free(i->sb->clickything);
		i->sb->clickything = new_image(i, 30, i->sb->size + 5);
		fill_image_with_colour(i->sb->clickything, 0xAAAAAA);
		old_hidden = num_hidden;
	}
	i->sb->start_no = map_number(i->sb->top_end, num_hidden, i->sb->top_start);
	mlx_put_image_to_window(i->mlx, i->win, i->sb->bg->img, TXTBX_END_W - 20,
			TXTBX_START_H);
	mlx_put_image_to_window(i->mlx, i->win, i->sb->clickything->img,
			TXTBX_END_W - 15, i->sb->top_start);
}

static void		string_display(t_interface *i)
{
	t_string	*traveller;
	int			start_height;

	traveller = i->s;
	start_height = (i->str_count > i->max_nodes) ? TXTBX_START_H :
		TXTBX_END_H - (i->str_count * 20);
	if (start_height == TXTBX_START_H && (i->sbon = 1))
		scrollbar_display(i, i->str_count - i->max_nodes);
	while (traveller)
	{
		if (--i->sb->start_no < 0)
		{
			if (start_height < TXTBX_END_H)
				mlx_string_put(i->mlx, i->win, TXTBX_START_W,
						start_height, 0x44AAFF, traveller->s);
			start_height += 20;
		}
		traveller = traveller->next;
	}
}

int				forever_loop(t_interface *i)
{
	mlx_put_image_to_window(i->mlx, i->win,
			i->bg->img, 0, 0);
	mlx_put_image_to_window(i->mlx, i->win,
			i->but->shadow->img, BUT_X - 10, BUT_Y + 10);
	if (i->bc)
	{
		mlx_put_image_to_window(i->mlx, i->win,
			i->but->connect->img, BUT_X - 10, BUT_Y + 10);
	}
	else
		mlx_put_image_to_window(i->mlx, i->win,
			i->but->connect->img, BUT_X, BUT_Y);
	string_display(i);
	return (1);
}
