/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:36:15 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/21 15:00:51 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# include "server.h"
# include "libft.h"
# include <mlx.h>
# include <pthread.h>
# include <math.h>

# define WIN_W 1600
# define WIN_H 1200
# define TXTBX_START_H 430
# define TXTBX_END_H 1150
# define TXTBX_START_W 100
# define TXTBX_END_W 1500

typedef struct			s_image
{
	void				*img;
	int					*pix;
	int					bpp;
	int					endian;
	int					w;
	int					h;
}						t_image;

typedef struct			s_scrollbar
{
	t_image				*bg;
	t_image				*clickything;
	int					size;
	int					top_start;
	int					top_end;
	int					y_diff;
	int					count;
}						t_scrollbar;

typedef struct			s_string
{
	char				*s;
	struct s_string		*next;
}						t_string;

typedef struct			s_interface
{
	void				*mlx;
	void				*win;
	t_image				*bg;
	t_string			*s;
	t_scrollbar			*sb;
	int					str_count;
	int					max_nodes;
	unsigned int		md:1;
	unsigned int		sbon:1;
}						t_interface;

t_interface				*initialize_i(void *mlx);
t_image					*new_image(t_interface *i, int width, int height);
t_image					*get_background(t_interface *i);
t_scrollbar				*get_scrollbar(t_interface *i);
void					fill_image_with_colour(t_image *i, int c);
int						mouse_press(int button, int x, int y, t_interface *i);
int						mouse_release(int button, int x, int y, t_interface *i);
int						mouse_move(int x, int y, t_interface *i);
int						exit_window(t_interface *i);
int						key_press(int keycode, t_interface *i);
int						forever_loop(t_interface *i);
void					draw_stuff(t_interface *i);
void					for_testing(t_interface *i);

t_string				*new_node(char *s);
t_string				*add_string_to_list(t_interface *i, char *new_string);

#endif
