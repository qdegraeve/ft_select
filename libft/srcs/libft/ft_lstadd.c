/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 09:59:27 by qdegraev          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/04/20 14:56:53 by qdegraev         ###   ########.fr       */
=======
/*   Updated: 2016/03/16 09:59:30 by qdegraev         ###   ########.fr       */
>>>>>>> b2bd455a799a00fa3386e8babf521c52cd2f1ef3
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
void		ft_lstadd(t_elem **alst, t_elem *new)
=======
void		ft_lstadd(t_list **alst, t_list *new)
>>>>>>> b2bd455a799a00fa3386e8babf521c52cd2f1ef3
{
	if (alst == NULL || new == NULL)
		return ;
	new->next = *alst;
	*alst = new;
}
