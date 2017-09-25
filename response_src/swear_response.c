/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swear_response.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 22:01:20 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/24 22:02:35 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*swear_response(char *str, int negation)
{
	(void)str;
	(void)negation;
	return (ft_strdup("don't be rude."));
}
