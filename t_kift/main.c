/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 19:27:11 by twalton           #+#    #+#             */
/*   Updated: 2017/09/07 19:27:11 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "respond.h"

int	main(int ac, char **av)
{
	char *response;

	if (ac != 2)
		return (0);
	response = respond(av[1]);
	write(1, response, strlen(response));
}
