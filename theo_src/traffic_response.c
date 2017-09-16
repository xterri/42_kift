/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traffic_response.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:28:07 by twalton           #+#    #+#             */
/*   Updated: 2017/09/07 22:28:07 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "respond.h"

char	*traffic_response(char *str, int negation)
{
	(void)str;
	if (negation)
		return (strdup("ok I won't tell you the traffic"));
	return (strdup("go check google maps"));
}
