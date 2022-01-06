/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:40:04 by lumfred           #+#    #+#             */
/*   Updated: 2021/11/28 14:04:37 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_num(unsigned long long num, int base, char flag)
{
	char		*alpha;
	char		*str;
	static char	buf[50];

	str = &buf[49];
	*str = '\0';
	alpha = "0123456789abcdef";
	if (flag == 'X')
		alpha = "0123456789ABCDEF";
	*--str = alpha[num % base];
	num /= base;
	while (num != 0)
	{
		*--str = alpha[num % base];
		num /= base;
	}
	return (str);
}

int	put_param(char traverse, va_list arg, struct s_flags *op)
{
	int	res;

	res = 0;
	if (traverse == 'c')
		res += process_c(arg, op);
	if (traverse == 's')
		res += process_s(arg, op);
	if (traverse == 'd' || traverse == 'i')
		res += process_d_i(traverse, arg, op);
	if (traverse == 'x' || traverse == 'X')
		res += process_x(traverse, arg, op);
	if (traverse == 'u')
		res += process_u(traverse, arg, op);
	if (traverse == 'p')
		res += process_p(traverse, arg, op);
	if (traverse == '%')
	{
		res += make_fl_d(1, op, !op->minus);
		ft_putchar_fd('%', 1);
		res += make_fl_d(1, op, op->minus);
	}
	return (res + (int)(traverse == '%'));
}

int	ft_printf(const char *string, ...)
{
	int				res;
	const char		*traverse;
	va_list			arg;
	struct s_flags	op;

	res = 0;
	va_start(arg, string);
	traverse = string;
	while (*traverse)
	{
		reset_flags(&op);
		while (*traverse != '%' && *traverse && (++res))
			ft_putchar_fd(*traverse++, 1);
		if (!*traverse)
			break ;
		if (!*++traverse)
			break ;
		traverse += process_flags(arg, (char *)traverse, &op);
		if (!*traverse)
			break ;
		res += put_param(*traverse++, arg, &op);
	}
	va_end(arg);
	return (res);
}
