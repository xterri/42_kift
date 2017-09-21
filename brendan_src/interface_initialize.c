/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_initialize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:41:01 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/20 16:01:04 by bpierce          ###   ########.fr       */
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
	if (button == 1)
		i->md = (x * y * 0) + 1;
	return (1);
}

static void		initialize_hooks(t_interface *i)
{
	mlx_do_key_autorepeatoff(i->mlx);
	mlx_hook(i->win, 4, 0, mouse_press, i);
	mlx_hook(i->win, 2, 0, key_press, i);
	//mlx_hook(i->win, 12, 0, expose_i_guess, i);
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
		return (ft_putnull("Failed to get scrollbar"));
	i->s = NULL;
	i->max_nodes = (TXTBX_END_H - TXTBX_START_H) / 20;
	i->win = mlx_new_window(i->mlx, WIN_W, WIN_H, "Say my name, say my name");
	mlx_put_image_to_window(i->mlx, i->win, i->bg->img, 0, 0);
	initialize_hooks(i);
	return (i);
}
