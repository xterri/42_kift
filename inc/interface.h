/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:36:15 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/19 19:23:20 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# include "server.h"
# include "libft.h"

# define WIN_W 400
# define WIN_H 800

typedef struct			s_image
{
	void				*img;
	int					*pix;
	int					bpp;
	int					endian;
	int					w;
	int					h;
}						t_image;

typedef struct			t_interface
{
	void				*mlx;
	void				*win;
	t_image				*bg;
}						s_interface;

s_interface				*initialize_i(void *mlx);
t_image					*new_image(t_interface *i, int width, int height);

#endif
