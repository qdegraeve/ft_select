/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 13:00:34 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/22 14:44:13 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_env	*get_env(t_env *e)
{
	static t_env *stat_e = NULL;

	if (e != NULL)
		stat_e = e;
	return (stat_e);
}

void	sig_handler(int sig)
{
	if (sig == SIGSTOP) {
			term_reset();
			exit(0);
			}
	else if (sig == SIGWINCH)
			display_choices(get_env(NULL));
	signal(sig, sig_handler);
}
