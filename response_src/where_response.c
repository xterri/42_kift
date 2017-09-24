/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_response.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:10:41 by twalton           #+#    #+#             */
/*   Updated: 2017/09/22 12:13:40 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*where_response(char *str, int negation)
{
	(void)str;
	(void)negation;
	return (ft_strdup("you are connected at the ip address of "));
}
