/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:58:25 by lumfred           #+#    #+#             */
/*   Updated: 2021/10/15 14:59:22 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*node;

	node = lst;
	if (!(lst == NULL || f == NULL))
	{
		while (node != NULL)
		{
			f(node->content);
			node = node->next;
		}
	}
}
