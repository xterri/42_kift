/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 14:46:02 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/25 14:26:20 by bpierce          ###   ########.fr       */
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
	if (x > BUT_X && x < BUT_X + i->but->connect->w)
		if (y > BUT_Y && y < BUT_Y + i->but->connect->h)
			i->bc = 1;
	return (button * x * y);
}

int				mouse_press(int button, int x, int y, t_interface *i)
{
	int		scroll_speed;

	scroll_speed = 20;
	if (y >= i->sb->top_start && y <= i->sb->top_start + i->sb->size)
		if (x >= TXTBX_END_W - 20 && x <= TXTBX_END_W + 20 && (i->sc = 1))
			i->sb->y_diff = y - i->sb->top_start;
	if (i->sbon)
	{
		if (button == 4 && i->sb->top_start >= TXTBX_START_H &&
				i->sb->top_start < i->sb->top_end)
			i->sb->top_start += (i->sb->top_start + scroll_speed) >
				(i->sb->top_end) ? (i->sb->top_end - i->sb->top_start) :
				scroll_speed;
		else if (button == 5 && i->sb->top_start <= i->sb->top_end &&
				i->sb->top_start > TXTBX_START_H)
			i->sb->top_start -= (i->sb->top_start - scroll_speed) <
				(TXTBX_START_H) ? i->sb->top_start - TXTBX_START_H :
				scroll_speed;
	}
	return (mouse_press2(button, x, y, i));
}

int				mouse_release(int button, int x, int y, t_interface *i)
{
	i->sc = 0;
	if (i->bc == 1)
	{
		i->but->but_to_display = i->but->connected;
		i->bc = 0;
	}
	return (button * x * y);
}

int				mouse_move(int x, int y, t_interface *i)
{
	(void)x;
	if (i->sbon == 1)
	{
		if (i->sc == 1)
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
