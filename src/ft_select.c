/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:40:45 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/25 11:47:30 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	term_set(void)
{
	char			*name;
	struct termios	term;

	name = getenv("TERM");
	tgetent(NULL, name);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &term);
	tputs(tgetstr("vi", NULL), 1, ft_putchar2);
}

void	term_reset(void)
{
	char			*name;
	struct termios	term;

	name = getenv("TERM");
	tputs(tgetstr("ve", NULL), 1, ft_putchar2);
	tgetent(NULL, name);
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
	env_init(&e);
	liste_init(&e.lst);
	while (i < ac)
	{
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
	int		i;

	i = 0;
	e = argv_copy(av, ac);
	term_set();
	ft_printf("ttyslot == %d\n", ttyslot());
	while (i < 33)
	{
		signal(i, sig_handler);
		i++;
	}
//	get_input(&e);
	term_reset();
	return (0);
}
