/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_buttons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:48:02 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/23 16:30:33 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

t_button		*get_buttons(t_interface *i)
{
	t_button	*but;

	if (!(but = (t_button *)ft_memalloc(sizeof(t_button))))
		return (ft_putnull("Failed to malloc size for t_button"));
	if (!(but->connect = new_xpm_image(i, "images/connect.xpm")))
		return (ft_putnull("Failed to get images/connect.xpm"));
	if (!(but->connected = new_xpm_image(i, "images/bg.xpm")))
		return (ft_putnull("Failed to get images/"));
	return (but);
}
