/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:31:30 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/25 21:57:35 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		col_display(t_env *e, int i)
{
	if (i < e->line)
	{
		tputs(tgoto(tgetstr("DO", NULL), 0, 1), 1, ft_putchar2);
		tputs(tgoto(tgetstr("LE", NULL), 0, e->length + 1), 1, ft_putchar2);
		e->up++;
		i++;
	}
	else if (e->line > 1)
	{
		tputs(tgoto(tgetstr("UP", NULL), 0, e->up), 1, ft_putchar2);
		i = 1;
		e->up = 0;
	}
	return (i);
}

void	initial_position(t_env *e)
{
	tputs(tgoto(tgetstr("LE", NULL), 0, e->col), 1, ft_putchar2);
	if (e->up > 0)
		tputs(tgoto(tgetstr("UP", NULL), 0, e->up), 1, ft_putchar2);
	tputs(tgetstr("cd", NULL), 1, ft_putchar2);
	e->up = 0;
}

int		define_print_disp(t_env *e)
{
	int				i;
	int				w_per_l;
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	e->col = win.ws_col;
	w_per_l = 0;
	w_per_l = e->col / (e->length + 1);
	i = e->lst.length / w_per_l;
	e->line = e->lst.length % w_per_l == 0 ? i : i + 1;
	if (e->line > win.ws_row)
		return (1);
	else
		return (0);
}

void	print_one(t_env *e, t_elem *elem, int i)
{
	t_choice				*c;
	unsigned long			j;

	j = 0;
	c = (t_choice*)elem->content;
	if (i == e->on)
		tputs(tgetstr("us", NULL), 1, ft_putchar2);
	if (c->sel == 1)
		tputs(tgetstr("mr", NULL), 1, ft_putchar2);
	if (i == e->on)
		ft_putstr_fd("\033[32m", e->fd);
	else
		ft_putstr_fd("\033[36m", e->fd);
	ft_putstr_fd(c->arg, e->fd);
	ft_putstr_fd("\033[0m", e->fd);
	tputs(tgetstr("me", NULL), 1, ft_putchar2);
	while (j++ <= e->length - ft_strlen(c->arg))
		ft_putstr_fd(" ", e->fd);
}

void	display_choices(t_env *e)
{
	int		i;
	int		k;
	t_elem	*elem;

	initial_position(e);
	k = define_print_disp(e);
	elem = e->lst.head;
	i = 0;
	if (k == 1)
		ft_printf("please resize screen");
	else
	{
		k = 1;
		while (i < e->lst.length)
		{
			print_one(e, elem, i);
			k = col_display(e, k);
			elem = elem->next;
			i++;
		}
	}
}
