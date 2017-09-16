/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 22:04:28 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/13 15:56:38 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iswhitespace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}
