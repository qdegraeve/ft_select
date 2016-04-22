/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:40:45 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/22 18:34:58 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>

int		ft_putchar2(int c)
{
	ft_putchar(c);
	return (0);
}

void		liste_init(t_list *lst)
{
	lst->head = NULL;
	lst->tail = NULL;
	lst->length = 0;
}

void		del_choice(void *c, size_t content_size)
{
	ft_strdel(&((t_choice*)c)->arg);
	ft_bzero(c, content_size);
	free(c);
}

void		term_set()
{
	int		i;
	char	*name = getenv ("TERM");
	struct termios term;

	i = 0;
	i = tgetent(NULL, name);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &term);
}

void		term_reset()
{
	int		i;
	char	*name = getenv ("TERM");
	struct termios term;

	i = 0;
	i = tgetent(NULL, name);
	tcgetattr(0, &term);
	term.c_lflag &= (ICANON | ECHO);
	tcsetattr(0, 0, &term);
}

t_env	argv_copy(char **av, int ac)
{
	t_env		e;
	t_choice	c;
	int			i;

	i = 1;
	liste_init(&e.lst);
	e.length = 0;
	while (i < ac)
	{
		e.on = 0;
		c.sel = 0;
		c.arg = NULL;
		if ((size_t)e.length < ft_strlen(av[i]))
			e.length = ft_strlen(av[i]);
		c.arg = ft_strdup(av[i]);
		ft_lstadd_last_circ(&e.lst, &c, sizeof(&c));
		i++;
	}
	return (e);
}

int		main(int ac, char **av)
{
	t_env	e;
	
	e = argv_copy(av, ac);
	term_set();
	move(&e);
	term_reset();
	return (0);
}
