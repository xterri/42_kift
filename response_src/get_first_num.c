/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:49:36 by twalton           #+#    #+#             */
/*   Updated: 2017/09/22 03:47:35 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	get_first_num(char *str)
{
	int i;

	i = 0;
	while (!ft_isdigit(str[i]) && str[i])
		++i;
	return (ft_atoi(str + i));
}
