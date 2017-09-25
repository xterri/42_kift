/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_response.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 22:20:33 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/25 14:17:58 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*how_response(char *str, int negation)
{
	char	neg[256];

	(void)str;
	if (negation)
	{
		ft_strcpy(neg, "I think you ought to know, I'm feeling very depressed. \
				Not like you care, nobody ever cares");
		return (ft_strdup(neg));
	}
	return (ft_strdup("I'm very fine, and you?"));
}
