/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_response.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:10:41 by twalton           #+#    #+#             */
/*   Updated: 2017/09/16 16:10:41 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*where_response(char *str, int negation)
{
	(void)str;
	(void)negation;
	return (strdup("%?"));
}
