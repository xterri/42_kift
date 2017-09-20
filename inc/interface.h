/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:36:15 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/20 12:42:15 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# include "server.h"
# include "libft.h"
# include <mlx.h>
# include <pthread.h>

# define WIN_W 1600
# define WIN_H 1200

typedef struct			s_image
{
	void				*img;
	int					*pix;
	int					bpp;
	int					endian;
	int					w;
	int					h;
}						t_image;

typedef struct			s_interface
{
	void				*mlx;
	void				*win;
	t_image				*bg;
}						t_interface;

t_interface				*initialize_i(void *mlx);
t_image					*new_image(t_interface *i, int width, int height);
t_image					*get_background(t_interface *i);
int						mouse_press(int button, int x, int y, t_interface *i);
int						exit_window(t_interface *i);
int						key_press(int keycode, t_interface *i);

#endif
