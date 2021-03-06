/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:41:04 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/25 21:09:45 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# define FT_SELECT_H

# define KUP	4283163
# define KDOWN	4348699
# define KLEFT	4479771
# define KRIGHT	4414235
# define ESC	27

# include <termcap.h>
# include <term.h>
# include <termios.h>
# include "../libft/include/ft_printf.h"
# include <sys/ioctl.h>
# include <signal.h>

typedef struct	s_env
{
	int			length;
	char		on;
	int			line;
	int			col;
	t_list		lst;
	int			up;
	int			fd;
	struct termios term;
}				t_env;

typedef struct	s_choice
{
	char		*arg;
	char		sel;
}				t_choice;

/*
**		main.c
*/
void			term_set();
void			term_reset(struct termios term);
int				ft_putchar2(int c);
void			del_choice(void *c, size_t content_size);

/*
**		display.c
*/
void			display_choices(t_env *e);
void			move(t_env *e);
void			initial_position(t_env *e);

/*
**		signals.c
*/
void	signal_catcher();
t_env			*get_env();

/*
**		keys.c
*/
void			get_input(t_env *e);
void			get_fd(t_env *e);

/*
**		actions.c
*/
void			chose_one(t_env *e);
void			remove_one(t_env *e);
void			selected(t_env *e);

/*
**		tools.c
*/
int				ft_putchar2(int c);
void			liste_init(t_list *lst);
void			env_init(t_env *e);
void			del_choice(void *c, size_t content_size);

#endif
