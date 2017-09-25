/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:33:41 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/25 15:32:06 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int			main(int argc, char **argv)
{
	void		*mlx;
	t_interface *i;
	pthread_t	t_id;
	t_args		a;

	a.argc = argc;
	a.argv = argv;
	mlx = mlx_init();
	if (!(i = initialize_i(mlx)))
		return (ft_puterror("Failed to initialize interface struct", 0));
	a.i = i;
	pthread_create(&t_id, NULL, client, &a);
	mlx_loop(mlx);
	return (1);
}
