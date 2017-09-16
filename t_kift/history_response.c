/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_response.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 23:12:21 by twalton           #+#    #+#             */
/*   Updated: 2017/09/07 23:12:21 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "respond.h"

char	*history_response(char *str, int negation)
{
	(void)str;
	if (negation)
		return (strdup("don't worry I won't show you your history"));
	return (strdup("ok let me show you your history"));
}
