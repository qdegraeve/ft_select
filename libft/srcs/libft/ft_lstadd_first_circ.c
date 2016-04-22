/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_first_circ.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:55:47 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/22 12:00:54 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int		ft_lstadd_first_circ(t_list *lst, void const *content, size_t cont_size)
{
	t_elem	*new;

	new = NULL;
	if (!(new = ft_lstnew(content, cont_size)))
		return (-1);
	if (lst->length == 0)
	{
		new->next = new;
		new->prev = new;
		lst->tail = new;
		lst->head = new;
		lst->length++;
	}
	else
	{
		new->prev = lst->tail;
		new->next = lst->head;
		lst->head->prev = new;
		lst->head = new;
		lst->tail->next = lst->head;
		lst->length++;
	}
	return (0);
}
