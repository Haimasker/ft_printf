/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:28:57 by lumfred           #+#    #+#             */
/*   Updated: 2021/11/29 10:28:59 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_s(char *str, struct s_flags *op)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < mnm(op->prec, ft_strlen(str)))
	{
		ft_putchar_if(str[i++], 1, op->dot);
		res++;
	}
	if (!op->dot)
		ft_putstr_fd(str, 1);
	return (res + (ft_strlen(str) * (int)(!op->dot)));
}

int	put_d_i(char *str, struct s_flags *op, int minus, int tmp)
{
	int	res;
	int	i;

	i = 0;
	if (!tmp && op->dot && !op->prec)
	{
		ft_putchar_if(op->plus_space, 1, op->plus && !minus);
		return ((int)(op->plus && !minus));
	}
	res = minus + (op->plus && !minus);
	if (op->plus && !(op->width > (int)ft_strlen(str) && !minus && op->zero))
		ft_putchar_fd(op->plus_space, 1);
	if (minus && !(op->width > (int)ft_strlen(str) && op->zero))
		ft_putchar_fd('-', 1);
	if (op->prec > (int)ft_strlen(str))
	{
		while (i++ < (op->prec - (int)ft_strlen(str)))
		{
			ft_putchar_fd('0', 1);
			res++;
		}
	}
	ft_putstr_fd(str, 1);
	return (res + ft_strlen(str));
}

int	put_x_u(char *str, struct s_flags *op, int tmp)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (!tmp && op->dot && !op->prec)
		return (0);
	if (op->prec > (int)ft_strlen(str) - (!tmp && op->dot && !op->prec))
	{
		while (i++ < op->prec - (int)ft_strlen(str)
			+ (!tmp && op->dot && !op->prec))
		{
			ft_putchar_fd('0', 1);
			res++;
		}
	}
	if (!(!tmp && op->dot && !op->prec))
	{
		ft_putstr_fd(str, 1);
		res += ft_strlen(str);
	}
	return (res);
}

int	process_p(char traverse, va_list arg, struct s_flags *op)
{
	unsigned long long	tmp;
	char				*str;
	int					res;

	tmp = va_arg(arg, unsigned long long);
	if (!tmp)
		str = "0";
	else
		str = convert_num(tmp, 16, traverse);
	res = make_fl_d(mxm((int)ft_strlen(str) + 2, op->prec + 2),
			op, !op->minus);
	ft_putstr_fd("0x", 1);
	res += put_x_u(str, op, tmp);
	res += make_fl_d(mxm((int)ft_strlen(str) + 2, op->prec + 2),
			op, op->minus);
	return (res + 2);
}
