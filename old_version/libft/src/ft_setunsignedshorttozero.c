/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setunsignedshorttozero.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 12:56:16 by bpierce           #+#    #+#             */
/*   Updated: 2017/08/18 13:17:27 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_setunsignedshorttozero(unsigned short *a, unsigned short *b,
		unsigned short *c, unsigned short *d)
{
	if (a)
		*a = 0;
	if (b)
		*b = 0;
	if (c)
		*c = 0;
	if (d)
		*d = 0;
	return ;
}
