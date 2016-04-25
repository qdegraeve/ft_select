/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 10:07:23 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/25 21:09:51 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	keys_action(t_env *e, int input)
{
	if (input == KUP)
		e->on = (e->on + e->lst.length - 1) % e->lst.length;
	else if (input == KDOWN)
		e->on = (e->on + 1) % e->lst.length;
	else if (input == KLEFT)
		e->on = (e->on + e->lst.length - e->line) % e->lst.length;
	else if (input == KRIGHT)
		e->on = (e->on + e->line) % e->lst.length;
	else if (input == 32)
		chose_one(e);
	else if (input == 127)
		remove_one(e);
	else if (input == 10)
		selected(e);
	else if (input == ESC)
	{
		initial_position(e);
		term_reset(e->term);
		exit(0);
	}
	else
		ft_printf("input == %d\n");
}

void	get_fd(t_env *e)
{
	int		fd = 0;

	e->fd = fd;
}

void	get_input(t_env *e)
{
	int		input;
	char	buf[5];

	input = 0;
	get_env(e);
	display_choices(e);
	ft_bzero(buf, 4);
	while (42)
	{
		read(0, buf, 4);
		buf[4] = '\0';
		input = (buf[3] << 24) + (buf[2] << 16) + (buf[1] << 8) + buf[0];
		keys_action(e, input);
		display_choices(e);
		ft_bzero(buf, 4);
	}
}
