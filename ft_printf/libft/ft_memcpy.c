/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:28:48 by lumfred           #+#    #+#             */
/*   Updated: 2021/10/20 14:08:39 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (src == NULL && dest == NULL)
		return (NULL);
	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	while (n--)
		*dest_tmp++ = *src_tmp++;
	return (dest);
}
