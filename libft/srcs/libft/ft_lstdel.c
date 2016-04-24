/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 09:59:51 by qdegraev          #+#    #+#             */
/*   Updated: 2016/04/22 15:28:13 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list *lst, t_elem **alst, void (*del)(void *, size_t))
{
	t_elem	*tmp;
	t_elem	*backup;

	if (*alst == NULL || del == NULL)
		return ;
	tmp = *alst;
	while (tmp)
	{
		backup = tmp->next;
		ft_lstdelone(lst, &tmp, (*del));
		tmp = backup;
	}
	*alst = NULL;
}
