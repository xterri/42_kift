/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:10:11 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/21 20:11:25 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

static int		map_number(t_interface *i, int num_of_hidden_nodes)
{
	int		oldrange;
	int		newrange;

	oldrange = (i->sb->top_end - TXTBX_START_H);
	newrange = (num_of_hidden_nodes - 0);
	return ((((i->sb->top_start - TXTBX_START_H) * newrange ) / oldrange) + 0);
}
static void		scrollbar_display(t_interface *i, int num_of_hidden_nodes)
{
	static int	old_num_of_hidden_nodes;

	i->sbon = 1;
	mlx_put_image_to_window(i->mlx, i->win, i->sb->bg->img, TXTBX_END_W - 20,
			TXTBX_START_H);
	if (old_num_of_hidden_nodes < num_of_hidden_nodes)
	{
		old_num_of_hidden_nodes = num_of_hidden_nodes;
		i->sb->size = (TXTBX_END_H - TXTBX_START_H + 5.0)
			* 1 / sqrt(num_of_hidden_nodes);
		mlx_destroy_image(i->mlx, i->sb->clickything->img);
		free(i->sb->clickything);
		i->sb->clickything = new_image(i, 40, i->sb->size);
		fill_image_with_colour(i->sb->clickything, 0xAAAAAA);
		i->sb->top_end = TXTBX_END_H - i->sb->size + 5.0;
	}
	i->sb->count = map_number(i, num_of_hidden_nodes);
	mlx_put_image_to_window(i->mlx, i->win, i->sb->clickything->img,
			TXTBX_END_W - 20, i->sb->top_start);	
}

static void		string_display(t_interface *i)
{
	t_string	*traveller;
	int			start_height;
	int			counter;

	traveller = i->s;
	start_height = (i->str_count > i->max_nodes) ? TXTBX_START_H :
		TXTBX_END_H - (i->str_count * 20);
	if (start_height == TXTBX_START_H)
		scrollbar_display(i, i->str_count - i->max_nodes);
	counter = i->sb->count;
	while (traveller)
	{
		if (counter-- < 0)
		{
			if (start_height < TXTBX_END_H)
				mlx_string_put(i->mlx, i->win, TXTBX_START_W,
						start_height, 0x44AAFF, traveller->s);
			start_height += 20;
		}
		traveller = traveller->next;
	}
}

void			for_testing(t_interface *i)
{
	static int	d;

	add_string_to_list(i, "TEST");
	add_string_to_list(i, "Halfling paladin");
	add_string_to_list(i, "Insert the dater");
	add_string_to_list(i, ft_itoa(d++));
}

void			draw_stuff(t_interface *i)
{
	mlx_put_image_to_window(i->mlx, i->win, i->bg->img, 0, 0);
	string_display(i);
}

int				forever_loop(t_interface *i)
{
	draw_stuff(i);
	return (1);
}
