/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 13:00:34 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/25 20:26:17 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_env	*get_env()
{
	static t_env *stat_e = NULL;

	if (!stat_e)
	{
		if (!(stat_e = (t_env*)malloc(sizeof(t_env))))
			ft_printf("caca\n");
	}
	return (stat_e);
}

void	end_select(int sig)
{
	if (sig != SIGWINCH && sig != SIGSTOP && sig != SIGCONT)
	{
		term_reset(get_env()->term);
		exit(0);
	}
}

void	resize(int sig)
{
	if (sig == SIGWINCH)
	{
		display_choices(get_env());
		signal(SIGWINCH, resize);
	}
}

void	suspend(int sig)
{
	char	away[2];
	if (sig == SIGTSTP)
	{
		term_reset(get_env()->term);
		signal(SIGTSTP, SIG_DFL);
		away[0] = get_env()->term.c_cc[VSUSP];
		away[1] = '\0';
		ioctl(0, TIOCSTI, away);
	}
}

void	restart(int sig)
{
	t_env	*e;

	e = get_env();
	if (sig == SIGCONT)
	{
		signal(SIGSTOP, suspend);
		term_set(e);
		display_choices(e);
	}
}

void	signal_catcher()
{
	int i;

	i = 0;
	signal(SIGWINCH, resize);
	signal(SIGTSTP, suspend);
	signal(SIGCONT, restart);
	while (i < 32)
	{
		if (i != SIGWINCH && i != SIGTSTP && i != SIGCONT)
			signal(i, end_select);
		i++;
	}

}
