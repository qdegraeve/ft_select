/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:31:30 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/22 20:51:37 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_one(t_env *e, t_elem *elem, int i)
{
	t_choice	*c;
	int			j;

	c = (t_choice*)elem->content;
	if (i == e->on)
		tputs(tgetstr("us", NULL), 1, ft_putchar2);
	if (c->sel == 1)
		tputs(tgetstr("mr", NULL), 1, ft_putchar2);
	j = ft_printf("%-s", c->arg);
	tputs(tgetstr("me", NULL), 1, ft_putchar2);
	ft_printf("%*s ", e->length - j, "");
}

int		col_display(t_env *e, int i)
{
	if (i < e->line) {
		tputs(tgoto(tgetstr("DO", NULL), 0, 1), 1, ft_putchar2);
		tputs(tgoto(tgetstr("LE", NULL), 0, e->length + 1), 1, ft_putchar2);
		e->up ++;
		i++;
	}
	else if (e->line > 1) {
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
	w_per_l = e->col / (e->length + 1);
	i = e->lst.length / w_per_l;
	e->line = e->lst.length % w_per_l == 0 ? i : i + 1;
	if (e->line > win.ws_row)
		return (1);
	else
		return (0);
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
	else {
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

void	chose_one(t_env *e)
{
	int i;
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
	int i;
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

void	move(t_env *e)
{
	int		input = 0;
	char	buf[5];

	e = get_env(e);
	display_choices(e);
	ft_bzero(buf, 4);
	while (42) {
		read(0, buf, 4);
		buf[4] = '\0';
		input = (buf[3] << 24) + (buf[2] << 16) + (buf[1] << 8) + buf[0];
		switch (input) {
			case KUP:
				e->on = (e->on + e->lst.length - 1) % e->lst.length;
				break;
			case KDOWN:
				e->on = (e->on + 1) % e->lst.length;
				break;
			case KLEFT:
				e->on = (e->on + e->lst.length - e->line) % e->lst.length;
				break;
			case KRIGHT:
				e->on = (e->on + e->line) % e->lst.length;
				break;
			case 32:
				chose_one(e);
				break;
			case 127:
				remove_one(e);
				break;
			case ESC:
				term_reset();
				exit(0);
		}
		display_choices(e);
		ft_bzero(buf, 4);
	}
}
