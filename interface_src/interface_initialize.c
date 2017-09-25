/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_initialize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:41:01 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/25 16:23:29 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int				exit_window(t_interface *i)
{
	send_terminator(i->socket->client_socket_fd);
	free_everything(i);
	exit(0);
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
	if (!(i->bg = new_xpm_image(i, "images/bg.xpm")))
		return (ft_putnull("Failed to get background image"));
	if (!(i->but = get_buttons(i)))
		return (ft_putnull("Failed to get connected"));
	if (!(i->sb = get_scrollbar(i)))
		return (ft_putnull("Failed to get scrollbar struct"));
	i->s = NULL;
	i->max_nodes = (TXTBX_END_H - TXTBX_START_H) / 20;
	i->win = mlx_new_window(i->mlx, WIN_W, WIN_H, "Say my name, say my name");
	initialize_hooks(i);
	return (i);
}
