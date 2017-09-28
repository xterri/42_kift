/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:11:10 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/28 13:57:23 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

t_string	*new_string_node(char *s, int colour)
{
	t_string	*new;

	if (!s)
		return (NULL);
	if (!(new = (t_string *)ft_memalloc(sizeof(t_string))))
		return (ft_putnull("Failed to malloc a new t_string"));
	new->s = strdup(s);
	new->c = colour;
	new->next = NULL;
	return (new);
}

t_string	*add_strings(t_string *n, char *string, int colour, int *cnt)
{
	char		tmp[MAX_STRING_LEN + 1];

	*cnt += 1;
	ft_bzero(tmp, MAX_STRING_LEN + 1);
	if (ft_strlen(string) > MAX_STRING_LEN)
	{
		ft_strncpy(tmp, string, MAX_STRING_LEN);
		n = new_string_node(tmp, colour);
		n->next = add_strings(n->next, &string[MAX_STRING_LEN], colour, cnt);
	}
	else
		n = new_string_node(string, colour);
	return (n);
}

static void	delete_first_node(t_interface *i)
{
	t_string	*for_deletion;

	for_deletion = i->s;
	i->s = i->s->next;
	free(for_deletion->s);
	free(for_deletion);
}

t_string	*add_string_to_list(t_interface *i, char *string, int colour)
{
	t_string	*new;

	if (string)
	{
		if (!i->s)
		{
			new = NULL;
			i->s = add_strings(new, string, colour, &i->str_count);
		}
		else
		{
			new = i->s;
			while (new->next)
				new = new->next;
			new->next = add_strings(new->next, string,
					colour, &i->str_count);
			while (i->str_count > MAX_STRINGS_TO_DISPLAY && --i->str_count)
				delete_first_node(i);
		}
	}
	return (i->s);
}
