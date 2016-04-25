/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 10:17:22 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/25 21:16:42 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	chose_one(t_env *e)
{
	int		i;
	t_elem	*elem;

	i = 0;
	elem = e->lst.head;
	while (i++ < e->on)
		elem = elem->next;
	((t_choice*)elem->content)->sel = (((t_choice*)elem->content)->sel + 1) % 2;
	e->on = (e->on + 1) % e->lst.length;
}

void	remove_one(t_env *e)
{
	int		i;
	t_elem	*elem;

	i = 0;
	elem = e->lst.head;
	while (i++ < e->on)
		elem = elem->next;
	ft_lstdelone(&e->lst, &elem, del_choice);
	if (!e->lst.head)
	{
		term_reset(e->term);
		exit(0);
	}
}

void	selected(t_env *e)
{
	int		i;
	int		j;
	t_elem	*elem;

	i = 0;
	j = 0;
	initial_position(e);
	elem = e->lst.head;
	while (i < e->lst.length - 1)
	{
		if (((t_choice*)elem->content)->sel == 1)
		{
			if (j++ > 0)
				ft_printf(" ");
			ft_printf("%s", ((t_choice*)elem->content)->arg);
		}
		elem = elem->next;
		i++;
	}
	term_reset(e->term);
	ft_lstdel(&e->lst, del_choice);
	exit(EXIT_SUCCESS);
}
