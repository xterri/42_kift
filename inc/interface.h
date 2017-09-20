/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:36:15 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/19 20:16:34 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# include "server.h"
# include "libft.h"
# include <mlx.h>
# include <pthread.h>

# define WIN_W 415
# define WIN_H 585

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

#endif
