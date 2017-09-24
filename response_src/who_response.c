/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_response.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:09:33 by twalton           #+#    #+#             */
/*   Updated: 2017/09/22 12:15:00 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*who_response(char *str, int negation)
{
	(void)str;
	(void)negation;
	return (ft_strdup("you are the only one connected to my heart / server"));
}
