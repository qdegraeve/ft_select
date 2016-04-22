/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 09:59:59 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/22 20:58:13 by qdegraev         ###   ########.fr       */
/*   Updated: 2016/03/16 10:00:01 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, t_elem **alst, void (*del)(void *, size_t))
{
	t_elem	*tmp;

	if (del == NULL || alst == NULL)
		return ;
	tmp = *alst;
	if (lst->length > 1) {
		if (tmp == lst->head)
			lst->head = tmp->next;
		if (tmp == lst->tail)
			lst->tail = tmp->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev;
		lst->length--;
	}
	del(tmp->content, tmp->content_size);
	free(*alst);
	*alst = NULL;
}
