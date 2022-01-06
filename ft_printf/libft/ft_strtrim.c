/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:06:50 by lumfred           #+#    #+#             */
/*   Updated: 2021/10/18 17:06:52 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len;

	if (!(s1 && set))
		return (NULL);
	while (*s1 && ft_strchr(set, (int)*s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, (int)s1[len]))
		len--;
	return (ft_substr((const char *)s1, (unsigned int)0, (size_t)(len + 1)));
}
