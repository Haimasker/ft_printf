/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:36:04 by lumfred           #+#    #+#             */
/*   Updated: 2021/10/20 11:29:10 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dest_len;

	i = 0;
	dest_len = 0;
	while (dest[dest_len] && dest_len < n)
		dest_len++;
	while ((src[i]) && (dest_len + i + 1) < n)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len != n)
		dest[dest_len + i] = '\0';
	return (dest_len + ft_strlen(src));
}
