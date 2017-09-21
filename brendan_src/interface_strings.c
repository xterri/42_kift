/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:11:10 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/20 14:29:16 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

t_string	*new_string_node(char *s)
{
	t_string	*new;

	if (!(new = (t_string *)ft_memalloc(sizeof(t_string))))
		return (ft_putnull("Failed to malloc a new t_string"));
	new->s = strdup(s);
	new->next = NULL;
	return (new);
}

t_string	*add_string_to_list(t_interface *i, char *new_string)
{
	t_string	*new;

	if (new_string)
	{
		if (!i->s)
			i->s = new_string_node(new_string);
		else
		{
			new = i->s;
			while (new->next)
				new = new->next;
			new->next = new_string_node(new_string);
		}
		i->str_count++;
	}
	return (i->s);
}

void		free_string_list(t_string *head)
{
	t_string	*deleteme;

	while (head)
	{
		deleteme = head;
		free(head->s);
		head = head->next;
		free(deleteme);
	}
}
