/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gats_response.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 21:53:42 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/25 16:54:06 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*gats_response(char *str, int negation)
{
	(void)str;
	if (negation)
		return (ft_strdup("okay I won't open gats.i o"));
	return (ft_strdup("opening up gats.i o"));
}
