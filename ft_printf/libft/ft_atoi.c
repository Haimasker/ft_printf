/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:37:41 by lumfred           #+#    #+#             */
/*   Updated: 2021/10/18 16:39:30 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		sign *= (44 - *str++);
	while (*str == '0')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		if (res == 2147483647 / 10 && (*str - '0' == 7 || *str - '0' == 8))
			return (sign * 2147483647 + ((sign - 1) / 2));
		if (res > 2147483647 / 10 || (res == 2147483647 / 10 && *str - '0' > 7))
			return ((-sign - 1) / 2);
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}
