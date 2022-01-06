/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:30:55 by lumfred           #+#    #+#             */
/*   Updated: 2021/10/18 16:42:26 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ch1;
	char	*ch2;

	if (dest == NULL || src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	i = 0;
	ch1 = (char *)dest;
	ch2 = (char *)src;
	if (ch1 > ch2)
		while (n-- > 0)
			ch1[n] = ch2[n];
	else
		while (i++ < n)
			*ch1++ = *ch2++;
	return (dest);
}
