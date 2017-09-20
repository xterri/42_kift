/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:33:41 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/19 20:37:10 by bpierce          ###   ########.fr       */
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
	dumb = ft_strdup(argv[0]);
	free(dumb);
	return (1);
}
