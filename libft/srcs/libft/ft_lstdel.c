/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 09:59:51 by qdegraev          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/04/22 15:28:13 by qdegraev         ###   ########.fr       */
=======
/*   Updated: 2016/03/16 09:59:52 by qdegraev         ###   ########.fr       */
>>>>>>> b2bd455a799a00fa3386e8babf521c52cd2f1ef3
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
void		ft_lstdel(t_list *lst, t_elem **alst, void (*del)(void *, size_t))
{
	t_elem	*tmp;
	t_elem	*backup;
=======
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*backup;
>>>>>>> b2bd455a799a00fa3386e8babf521c52cd2f1ef3

	if (*alst == NULL || del == NULL)
		return ;
	tmp = *alst;
	while (tmp)
	{
		backup = tmp->next;
<<<<<<< HEAD
		ft_lstdelone(lst, &tmp, (*del));
=======
		ft_lstdelone(&tmp, (*del));
>>>>>>> b2bd455a799a00fa3386e8babf521c52cd2f1ef3
		tmp = backup;
	}
	*alst = NULL;
}
