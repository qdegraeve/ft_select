/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:00:19 by qdegraev          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/04/20 15:20:05 by qdegraev         ###   ########.fr       */
=======
/*   Updated: 2016/03/16 10:00:21 by qdegraev         ###   ########.fr       */
>>>>>>> b2bd455a799a00fa3386e8babf521c52cd2f1ef3
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
t_elem		*ft_lstmap(t_elem *lst, t_elem *(*f)(t_elem *elem))
{
	t_elem *new;
	t_elem *tmp;
=======
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;
>>>>>>> b2bd455a799a00fa3386e8babf521c52cd2f1ef3

	if (lst == NULL || f == NULL)
		return (NULL);
	new = NULL;
	while (lst)
	{
		if (!new)
		{
			new = f(lst);
			tmp = new;
		}
		else
		{
			tmp->next = f(lst);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (new);
}
