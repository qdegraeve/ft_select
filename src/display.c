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

void	display_choices(t_env *e)
{
	int i;
	int k;
	int w_per_l;
	t_elem *elem;
	t_choice *c;

	i = 0;
	elem = e->lst.head;
	e->col = tgetnum("co");
	w_per_l = e->col / (e->length + 8);
	k = e->lst.length / w_per_l;
	e->line = e->lst.length % w_per_l == 0 ? k : k + 1;
	ft_printf("--- e-col == %d e->length == %d e->line == %d w_per_l == %d ---\n", e->col, e->length, e->line, w_per_l);
	e->up = 0;
	e->left = 0;
	k = 1;
	while (i < e->lst.length)
	{
		c = (t_choice*)elem->content;
		if (i == e->on)
			tputs(tgetstr("us", NULL), 1, ft_putchar2);
		if (c->sel == 1)
			tputs(tgetstr("mr", NULL), 1, ft_putchar2);
		e->left = ft_printf("%3d -- %-*s ",i ,e->length, c->arg);
//		ft_printf("e->left == %d k == %d\n\n\n", e->left, k);
		tputs(tgetstr("me", NULL), 1, ft_putchar2);
		if (k < e->line) {
			if (e->up == 0)
			{
		//		DEBUG
				ft_putchar('\n');
			}
//			else
//				tputs(tgetstr("do", NULL), 1, ft_putchar2);
			tputs(tgoto(tgetstr("LE", NULL), e->length + 8, 0), 1, ft_putchar2);
			e->up++;
			k++;
		}
		else {
			tputs(tgoto(tgetstr("UP", NULL), 0, e->up), 1, ft_putchar2);
			k = 0;
			e->up = 0;
		}
		elem = elem->next;
		i++;
	}
	e->left = (e->length + 8) * w_per_l;
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

}

void	move(t_env *e)
{
	int		input = 0;
	char *area = NULL;
	char	buf[5];
	int i;

	i = 0;
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
			tputs(tgoto(tgetstr("RI", &area), 0, 30), 1, ft_putchar2);
				e->on = (e->on + 1) % e->lst.length;
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
		tputs(tgoto(tgetstr("LE", &area), e->left, 0), 1, ft_putchar2);
		tputs(tgoto(tgetstr("UP", &area), 0, e->line), 1, ft_putchar2);
		tputs(tgetstr("cd", &area), 1, ft_putchar2);
		display_choices(e);
		ft_bzero(buf, 4);
	}
}
