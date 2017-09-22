/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_initialize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:41:01 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/21 19:44:47 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int				exit_window(t_interface *i)
{
	(void)i;
	exit(0);
	return (1);
}

int				key_press(int keycode, t_interface *i)
{
	(void)i;
	if (keycode == 53)
		exit(0);
	return (1);
}

int				mouse_press(int button, int x, int y, t_interface *i)
{
	int		scroll_speed;

	scroll_speed = 20;
	if (button == 3)
	{
		for_testing(i);
		draw_stuff(i);
	}
	else if (button == 1)
		if (y >= i->sb->top_start && y <= i->sb->top_start + i->sb->size)
			if (x >= TXTBX_END_W - 20 && x <= TXTBX_END_W + 20 && (i->md = 1))
				i->sb->y_diff = y - i->sb->top_start;
	if (button == 4)
		if (i->sbon == 1)
			if (i->sb->top_start >= TXTBX_START_H &&
					i->sb->top_start < TXTBX_END_H - (i->sb->size + scroll_speed))
				i->sb->top_start += scroll_speed;
	if (button == 5)
		if (i->sbon == 1)
			if (i->sb->top_start > TXTBX_START_H + scroll_speed &&
					i->sb->top_start <= TXTBX_END_H - (i->sb->size))
				i->sb->top_start -= scroll_speed;
	return (1);
}

int				mouse_release(int button, int x, int y, t_interface *i)
{
	(void)button;
	(void)x;
	(void)y;
	i->md = 0;
	return (1);
}

int				mouse_move(int x, int y, t_interface *i)
{
	(void)x;
	if (i->sbon == 1)
	{
		if (i->md == 1)
			if (!(y - i->sb->y_diff <= TXTBX_START_H) && !(y - i->sb->y_diff >= i->sb->top_end))
				i->sb->top_start = y - i->sb->y_diff;
	}
	return (1);
}

static void		initialize_hooks(t_interface *i)
{
	mlx_do_key_autorepeatoff(i->mlx);
	mlx_hook(i->win, 4, 0, mouse_press, i);
	mlx_hook(i->win, 5, 0, mouse_release, i);
	mlx_hook(i->win, 6, 0, mouse_move, i);
	mlx_hook(i->win, 2, 0, key_press, i);
	mlx_hook(i->win, 17, 0, exit_window, i);
	mlx_loop_hook(i->mlx, forever_loop, i);
}

t_interface		*initialize_i(void *mlx)
{
	t_interface		*i;

	if (!(i = (t_interface *)ft_memalloc(sizeof(t_interface))))
		return (ft_putnull("Failed to malloc for s_interface"));
	i->mlx = mlx;
	if (!(i->bg = get_background(i)))
		return (ft_putnull("Failed to get background image"));
	if (!(i->sb = get_scrollbar(i)))
		return (ft_putnull("Failed to get scrollbar struct"));
	i->s = NULL;
	i->max_nodes = (TXTBX_END_H - TXTBX_START_H) / 20;
	i->win = mlx_new_window(i->mlx, WIN_W, WIN_H, "Say my name, say my name");
	initialize_hooks(i);
	return (i);
}
