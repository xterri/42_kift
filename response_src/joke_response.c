/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joke_response.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 22:28:27 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/24 22:29:40 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*joke_response(char *str, int negation)
{
	(void)str;
	if (negation)
		return (ft_strdup("okay, I won't tell you a joke"));
	return (ft_strdup("< insert joke here >"));
}
