/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 22:19:47 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/25 16:26:19 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

static void	free_scrollbar(t_interface *i)
{
	mlx_destroy_image(i->mlx, i->sb->bg->img);
	mlx_destroy_image(i->mlx, i->sb->clickything->img);
	free(i->sb->bg);
	free(i->sb->clickything);
	free(i->sb);
}

static void	free_xpm_images(t_interface *i)
{
	mlx_destroy_image(i->mlx, i->but->connect->img);
	mlx_destroy_image(i->mlx, i->but->shadow->img);
	mlx_destroy_image(i->mlx, i->but->connected->img);
	mlx_destroy_image(i->mlx, i->bg->img);
	free(i->but->connect);
	free(i->but->shadow);
	free(i->but->connected);
	free(i->but);
	free(i->bg);
}

static void	free_string_list(t_string *head)
{
	t_string	*deleteme;

	while (head)
	{
		deleteme = head;
		free(head->s);
		head = head->next;
		free(deleteme);
	}
}

void		free_everything(t_interface *i)
{
	free_scrollbar(i);
	free_xpm_images(i);
	free_string_list(i->s);
	mlx_destroy_window(i->mlx, i->win);
	free(i);
}
