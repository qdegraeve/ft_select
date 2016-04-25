/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 10:17:22 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/25 10:52:46 by qdegraev         ###   ########.fr       */
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
		term_reset();
		exit(0);
	}
}
