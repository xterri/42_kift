/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:33:41 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/19 19:59:14 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

int		main(int argc, char **argv)
{
	void		*mlx;
	t_interface	*i;
	char		*dumb;

	if (argc != 1)
		return (ft_puterror("usage: Run the program with no arguments", 0));
	mlx = mlx_init();
	if (!(i = initialize_i(mlx)))
		return (ft_puterror("Failed to initialize interface struct", 0));
	mlx_loop(mlx);
	dumb = argv[0];
	return (1);
}
