/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bye_response.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:37:52 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/24 21:56:06 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*bye_response(char *str, int negation)
{
	(void)str;
	(void)negation;
	return (ft_strdup("bye bye now"));
}
