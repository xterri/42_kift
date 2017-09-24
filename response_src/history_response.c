/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_response.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 23:12:21 by twalton           #+#    #+#             */
/*   Updated: 2017/09/22 03:48:44 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*history_response(char *str, int negation)
{
	(void)str;
	if (negation)
		return (ft_strdup("don't worry I won't show you your history"));
	return (ft_strdup("ok let me show you your history"));
}
