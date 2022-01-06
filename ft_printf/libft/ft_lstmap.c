/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:59:32 by lumfred           #+#    #+#             */
/*   Updated: 2021/10/15 15:00:51 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*lst_res;
	t_list	*node;

	if (f == NULL || lst == NULL)
		return (NULL);
	lst_res = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&lst_res, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_res, node);
		lst = lst->next;
	}
	return (lst_res);
}
