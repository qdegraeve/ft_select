/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 10:30:19 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/25 21:32:26 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_putchar2(int c)
{
	ft_putchar_fd(c, get_env(NULL)->fd);
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
	char	*tmp;

	e->length = 0;
	e->up = 0;
	e->line = 0;
	e->on = 0;
	e->col = 0;
	e->fd = 0;
	e->fd = open(tmp = ttyname(STDIN_FILENO), O_RDWR);
	ft_strdel(&tmp);
}

void	del_choice(void *c, size_t content_size)
{
	ft_strdel(&((t_choice*)c)->arg);
	ft_bzero(c, content_size);
	free(c);
}
