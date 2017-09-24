/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traffic_response.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:28:07 by twalton           #+#    #+#             */
/*   Updated: 2017/09/22 03:50:19 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*traffic_response(char *str, int negation)
{
	(void)str;
	if (negation)
		return (ft_strdup("ok I won't tell you the traffic"));
	return (ft_strdup("go check google maps"));
}
