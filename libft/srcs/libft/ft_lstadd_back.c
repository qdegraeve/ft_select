/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 09:59:40 by qdegraev          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/04/20 14:56:33 by qdegraev         ###   ########.fr       */
=======
/*   Updated: 2016/03/16 09:59:42 by qdegraev         ###   ########.fr       */
>>>>>>> b2bd455a799a00fa3386e8babf521c52cd2f1ef3
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
void	ft_lstadd_back(t_elem **beg_lst, void const *content, size_t cont_size)
{
	t_elem	*new;
	t_elem	*tmp;
=======
void	ft_lstadd_back(t_list **beg_lst, void const *content, size_t cont_size)
{
	t_list	*new;
	t_list	*tmp;
>>>>>>> b2bd455a799a00fa3386e8babf521c52cd2f1ef3

	new = NULL;
	tmp = NULL;
	if (!(new = ft_lstnew(content, cont_size)))
		return ;
	if (!(*beg_lst))
		*beg_lst = new;
	else
	{
		tmp = *beg_lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}
