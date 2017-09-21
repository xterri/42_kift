/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:10:11 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/20 16:04:19 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

static void	string_display(t_interface *i)
{
	t_string	*traveller;
	int			start_height;
	int			counter;

	traveller = i->s;
	counter = i->str_count - i->max_nodes;
	start_height = (i->str_count > i->max_nodes) ? TXTBX_START_H :
		TXTBX_END_H - (i->str_count * 20);
	while (traveller)
	{
		if (!(counter-- > 0))
		{
			if (start_height < TXTBX_END_H)
				mlx_string_put(i->mlx, i->win, TXTBX_START_W,
						start_height, 0x55AAFF, traveller->s);
			start_height += 20;
		}
		traveller = traveller->next;
	}
	mlx_put_image_to_window(i->mlx, i->win, i->sb->bg->img, TXTBX_END_W - 20,
			TXTBX_START_H);
	mlx_put_image_to_window(i->mlx, i->win, i->sb->clickything->img, TXTBX_END_W - 20,
			TXTBX_START_H);
}

static void	for_testing(t_interface *i)
{
	add_string_to_list(i, "TEST");
	add_string_to_list(i, "Halfling paladin");
	add_string_to_list(i, "Insert the dater");
	add_string_to_list(i, "OFFSET the dater");
}

int			forever_loop(t_interface *i)
{
	if (i->md == 1)
	{
		i->md = 0;
		for_testing(i);
		mlx_put_image_to_window(i->mlx, i->win, i->bg->img, 0, 0);
		string_display(i);
	}
	return (1);
}
