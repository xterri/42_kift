/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_standby.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 15:22:40 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/24 15:40:33 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	client_standby(t_interface *i)
{
	while (!i->bc)
		;
}
