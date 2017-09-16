/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelthree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:45:21 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/22 15:41:12 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdelthree(char **as, char **as2, char **as3)
{
	ft_strdel(as);
	ft_strdel(as2);
	ft_strdel(as3);
}
