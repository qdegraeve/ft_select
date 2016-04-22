/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:00:28 by qdegraev          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/04/20 19:29:07 by qdegraev         ###   ########.fr       */
=======
/*   Updated: 2016/03/16 10:00:33 by qdegraev         ###   ########.fr       */
>>>>>>> b2bd455a799a00fa3386e8babf521c52cd2f1ef3
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
t_elem		*ft_lstnew(void const *content, size_t content_size)
{
	t_elem		*new;

	new = NULL;
	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (NULL);
	ft_bzero(new, sizeof(t_elem));
=======
t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = NULL;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	ft_bzero(new, sizeof(t_list));
>>>>>>> b2bd455a799a00fa3386e8babf521c52cd2f1ef3
	new->content_size = 0;
	new->content = NULL;
	if (content == NULL)
		return (new);
	else
	{
		new->content_size = content_size;
<<<<<<< HEAD
		if (!(new->content = malloc(content_size + 1)))
=======
		if (!(new->content = malloc(content_size)))
>>>>>>> b2bd455a799a00fa3386e8babf521c52cd2f1ef3
			return (NULL);
		ft_bzero(new->content, content_size);
		ft_memcpy(new->content, content, content_size);
	}
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
