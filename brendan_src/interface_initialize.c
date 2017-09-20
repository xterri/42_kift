/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_initialize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:41:01 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/19 18:35:26 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

static void		initialize_hooks(t_rt *rt)
{
	mlx_do_key_autorepeatoff(rt->mlx);
	mlx_hook(rt->win, 4, 0, mouse_press, rt);
	mlx_hook(rt->win, 12, 0, expose_i_guess, rt);
	mlx_hook(rt->win, 17, 0, exit_window, rt);
	mlx_loop_hook(rt->mlx, forever_loop, rt);
}

static t_image	*get_background(t_interface *i)
{
	t_image	*bg;

	if (!(bg = (t_image *)ft_memalloc(sizeof(t_image))))
		return (ft_putnull("Failed to malloc space for bg"));
	bg->img = mlx_xpm_file_to_image(w->mlx, "images/bg.xpm", &bg->w, &bg->h);
	return (image);
}

s_interface		*initialize_i(void *mlx)
{
	t_interface		*i;

	if (!(i = (s_interface *)ft_memalloc(sizeof(s_interface))))
		return (ft_putnull("Failed to malloc for s_interface"));
	i->mlx = mlx;
	if (!(i->bg = get_background(i)))
		return (ft_putnull("Failed to get background image"));
	i->win = mlx_new_window(i->mlx, WIN_W, WIN_H, "Say my name, say my name");
}
