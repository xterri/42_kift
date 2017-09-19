/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bye_response.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:37:52 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/19 14:42:54 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*bye_response(char *str, int negation)
{
	(void)str;
	if (negation)
		return (strdup("ok I won't let you go"));
	return (strdup("bye bye now"));
}
