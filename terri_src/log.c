/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 17:23:08 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/16 18:48:03 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	log(char *str, void *socket)
{
	// if "name_log.csv" file does not exist (doesn't open to append?)
	// can also check if file exists with "access(<file>, F_OK)"
		// pass to sprintf to create the file first
			// or use fopen with write?
	// else if file opens/exists
		// append to the file (should be okay to use and/or create file)
		// fprintf to the file the NAME, DATE/TIME, IP, COMMENT
		// close file
}
