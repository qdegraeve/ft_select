/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 10:30:19 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/25 10:41:21 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_putchar2(int c)
{
	ft_putchar(c);
	return (0);
}

void	liste_init(t_list *lst)
{
	lst->head = NULL;
	lst->tail = NULL;
	lst->length = 0;
}

void	env_init(t_env *e)
{
	e->length = 0;
	e->up = 0;
	e->line = 0;
	e->on = 0;
	e->col = 0;
}

void	del_choice(void *c, size_t content_size)
{
	ft_strdel(&((t_choice*)c)->arg);
	ft_bzero(c, content_size);
	free(c);
}
