/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:33:41 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/24 15:54:12 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void		*interface(void *j)
{
	void		*mlx;
	t_interface *i;

	i = (t_interface *)j;
	mlx = mlx_init();
	if (!(i = initialize_i(mlx)))
		return (ft_putnull("Failed to initialize interface struct"));
	mlx_loop(mlx);
	return (NULL);
}