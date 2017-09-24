/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 17:20:25 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/24 15:52:23 by bpierce          ###   ########.fr       */
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

# define BUT_X 900
# define BUT_Y 100

# define MAX_STRINGS_TO_DISPLAY 200

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
	int					start_no;
}						t_scrollbar;

typedef struct			s_button
{
	t_image				*connect;
	t_image				*shadow;
	t_image				*connected;
}						t_button;

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
	t_button			*but;
	t_string			*s;
	t_scrollbar			*sb;
	int					str_count;
	int					max_nodes;
	unsigned int		sc:1;
	unsigned int		sbon:1;
	unsigned int		bc:1;
	unsigned int		connected:1;
}						t_interface;

void					client_standby(t_interface *i);
void					*interface(void *j);
t_interface				*initialize_i(void *mlx);
t_image					*new_image(t_interface *i, int width, int height);
t_image					*new_xpm_image(t_interface *i, char *image_address);
t_button				*get_buttons(t_interface *i);
t_scrollbar				*get_scrollbar(t_interface *i);
void					fill_image_with_colour(t_image *i, int c);
int						mouse_press(int button, int x, int y, t_interface *i);
int						mouse_release(int button, int x, int y, t_interface *i);
int						mouse_move(int x, int y, t_interface *i);
int						exit_window(t_interface *i);
int						key_press(int keycode, t_interface *i);
int						forever_loop(t_interface *i);
t_string				*new_node(char *s);
t_string				*add_string_to_list(t_interface *i, char *new_string);
void					free_everything(t_interface *i);

#endif
