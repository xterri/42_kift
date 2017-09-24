/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   email_response.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:43:19 by twalton           #+#    #+#             */
/*   Updated: 2017/09/22 03:46:48 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*email_response(char *str, int negation)
{
	(void)str;
	if (negation)
		return (ft_strdup("ok I won't send an email"));
	return (ft_strdup("ok let me open your email"));
}
