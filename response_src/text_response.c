/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_response.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:11:10 by twalton           #+#    #+#             */
/*   Updated: 2017/09/22 03:50:08 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*text_response(char *str, int negation)
{
	(void)negation;
	(void)str;
	return (ft_strdup("your device does not support the kift message app"));
}
