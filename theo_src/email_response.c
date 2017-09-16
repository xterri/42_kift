/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   email_response.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:43:19 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 20:06:18 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*email_response(char *str, int negation)
{
	(void)str;
	if (negation)
		return (strdup("ok I won't send an email"));
	return (strdup("ok let me open your email"));
}
