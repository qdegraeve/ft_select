/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:40:45 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/25 21:58:53 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	term_set()
{
	char			*name;

	name = getenv("TERM");
	tgetent(NULL, name);
	tcgetattr(0, &get_env()->term);
	get_env()->term.c_lflag &= ~(ICANON | ECHO);
	get_env()->term.c_cc[VMIN] = 1;
	get_env()->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &get_env()->term);
	tputs(tgetstr("vi", NULL), 0, ft_putchar2);
}

void	term_reset(struct termios term)
{
	tputs(tgetstr("ve", NULL), 1, ft_putchar2);
	tcsetattr(0, TCSADRAIN, &term);
}

t_env	*argv_copy(char **av, int ac)
{
	t_env		*e;
	t_choice	c;
	int			i;

	i = 1;
	e = NULL;
	c.sel = 0;
	e = get_env();
	env_init(e);
	liste_init(&e->lst);
	while (i < ac)
	{
		c.sel = 0;
		c.arg = NULL;
		if ((size_t)e->length < ft_strlen(av[i]))
			e->length = ft_strlen(av[i]);
		c.arg = ft_strdup(av[i]);
		ft_lstadd_last_circ(&e->lst, &c, sizeof(c));
		i++;
	}
	term_set();
	return (e);
}

int		main(int ac, char **av)
{
	t_env	*e;
	int		i;

	i = 0;
	e = argv_copy(av, ac);
	signal_catcher();
	get_input(e);
	return (0);
}
