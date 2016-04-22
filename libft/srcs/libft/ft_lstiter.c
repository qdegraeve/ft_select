/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:00:09 by qdegraev          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/04/20 15:20:26 by qdegraev         ###   ########.fr       */
=======
/*   Updated: 2016/03/16 10:00:11 by qdegraev         ###   ########.fr       */
>>>>>>> b2bd455a799a00fa3386e8babf521c52cd2f1ef3
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
void		ft_lstiter(t_elem *lst, void (*f)(t_elem *elem))
{
	t_elem	*backup;
=======
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*backup;
>>>>>>> b2bd455a799a00fa3386e8babf521c52cd2f1ef3

	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		backup = lst->next;
		f(lst);
		lst = backup;
	}
}
