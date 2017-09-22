/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:11:10 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/21 20:09:35 by bpierce          ###   ########.fr       */
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

static void	delete_first_node(t_interface *i)
{
	t_string	*for_deletion;

	for_deletion = i->s;
	i->s = i->s->next;
	free(for_deletion->s);
	free(for_deletion);
}

t_string	*add_string_to_list(t_interface *i, char *new_string)
{
	t_string	*new;
	int			counter;

	if (new_string)
	{
		counter = 1;
		if (!i->s)
			i->s = new_string_node(new_string);
		else
		{
			new = i->s;
			while (new->next)
			{
				counter++;
				new = new->next;
			}
			if (counter == MAX_STRINGS_TO_DISPLAY)
				delete_first_node(i);
			new->next = new_string_node(new_string);
		}
		i->str_count += (counter == MAX_STRINGS_TO_DISPLAY) ? 0 : 1;
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
