/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:00:19 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/20 15:20:05 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_elem		*ft_lstmap(t_elem *lst, t_elem *(*f)(t_elem *elem))
{
	t_elem *new;
	t_elem *tmp;

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
