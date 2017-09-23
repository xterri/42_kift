/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 14:46:02 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/23 16:36:15 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int				key_press(int keycode, t_interface *i)
{
	if (keycode == 53)
		exit_window(i);
	return (1);
}

static int		mouse_press2(int button, int x, int y, t_interface *i)
{

}

int				mouse_press(int button, int x, int y, t_interface *i)
{
	int		scroll_speed;

	scroll_speed = 20;
	if (button == 1)
		if (y >= i->sb->top_start && y <= i->sb->top_start + i->sb->size)
			if (x >= TXTBX_END_W - 20 && x <= TXTBX_END_W + 20 && (i->md = 1))
				i->sb->y_diff = y - i->sb->top_start;
	if (i->sbon)
	{
		if (button == 4 && i->sb->top_start >= TXTBX_START_H &&
				i->sb->top_start < i->sb->top_end)
		{
			i->sb->top_start += (i->sb->top_start + scroll_speed) >
				(i->sb->top_end) ? (i->sb->top_end - i->sb->top_start) :
				scroll_speed;
		}
		else if (button == 5 && i->sb->top_start <= i->sb->top_end &&
				i->sb->top_start > TXTBX_START_H)
		{
			i->sb->top_start -= (i->sb->top_start - scroll_speed) <
				(TXTBX_START_H) ? i->sb->top_start - TXTBX_START_H :
				scroll_speed;
		}
	}
	return ((x * 0) + 1);
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
		{
			i->sb->top_start = y - i->sb->y_diff;
			if (i->sb->top_start < TXTBX_START_H)
				i->sb->top_start = TXTBX_START_H;
			else if (i->sb->top_start > i->sb->top_end)
				i->sb->top_start = i->sb->top_end;
		}
	}
	return (1);
}
