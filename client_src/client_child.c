/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 02:47:19 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/22 02:49:27 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	client_child(t_socket *s)
{
	dup2(s->fds[1], 1);
	system("pocketsphinx_continuous -inmic yes -lm lm_dict/4510.lm \
			-dict lm_dict/4510.dic -logfn /dev/null");
	close(s->fds[1]);
	dup2(s->stdout_save, 1);
}
