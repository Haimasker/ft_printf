/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:03:10 by lumfred           #+#    #+#             */
/*   Updated: 2021/11/28 14:57:10 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_c(va_list arg, struct s_flags *op)
{
	int	res;

	res = make_fl_s(1, op, !op->minus);
	ft_putchar_fd((char)va_arg(arg, int), 1);
	res += make_fl_s(1, op, op->minus);
	return (res + 1);
}

int	process_s(va_list arg, struct s_flags *op)
{
	char	*tmp;
	char	*str;
	int		res;

	tmp = va_arg(arg, char *);
	if (tmp)
		str = tmp;
	else
		str = "(null)";
	res = make_fl_s(mnm(op->prec, ft_strlen(str)), op, op->dot && !op->minus);
	res += make_fl_s((int)ft_strlen(str), op, !op->dot && !op->minus);
	res += put_s(str, op);
	res += make_fl_s((int)ft_strlen(str), op, !op->dot && op->minus);
	res += make_fl_s(mnm(op->prec, ft_strlen(str)), op, op->dot && op->minus);
	return (res);
}

int	process_d_i(char traverse, va_list arg, struct s_flags *op)
{
	char	*str;
	int		res;
	int		tmp;
	int		minus;

	tmp = va_arg(arg, int);
	if (tmp == -2147483648)
		return (process_min_int(op));
	op->plus &= ((~((int)(tmp >= 0) << 31)) + (int)(tmp < 0));
	minus = 0 | (!((~((int)(tmp >= 0) << 31)) + (int)(tmp < 0)));
	tmp = (tmp ^ (tmp >> 31)) - (tmp >> 31);
	op->zero &= !(op->dot);
	str = convert_num((unsigned long long)tmp, 10, traverse);
	if (!tmp && !op->prec && op->dot)
		str = "";
	ft_putchar_if(op->plus_space, 1, op->width > (int)ft_strlen(str)
		&& !minus && op->zero && op->plus);
	ft_putchar_if('-', 1, op->width > (int)ft_strlen(str)
		&& minus && op->zero);
	res = make_fl_d(mxm((int)ft_strlen(str), op->prec) + minus
			+ (op->plus && !minus), op, !op->minus);
	res += put_d_i(str, op, minus, tmp);
	res += make_fl_d(mxm((int)ft_strlen(str), op->prec) + minus
			+ (op->plus && !minus), op, op->minus);
	return (res);
}

int	process_u(char traverse, va_list arg, struct s_flags *op)
{
	unsigned int	tmp;
	char			*str;
	int				res;

	tmp = va_arg(arg, unsigned int);
	str = convert_num(tmp, 10, traverse);
	op->zero &= !(op->dot && (op->prec < op->width));
	if (!tmp && !op->prec && op->dot)
		str = "";
	res = make_fl_d(mxm((int)ft_strlen(str), op->prec), op, !op->minus);
	res += put_x_u(str, op, tmp);
	res += make_fl_d(mxm((int)ft_strlen(str), op->prec), op, op->minus);
	return (res);
}

int	process_x(char tr, va_list arg, struct s_flags *op)
{
	unsigned int	tmp;
	char			*str;
	int				res;
	int				l;

	tmp = va_arg(arg, unsigned int);
	str = convert_num(tmp, 16, tr);
	l = (int)ft_strlen(str);
	op->zero &= !(op->dot && (op->prec < op->width));
	if (!tmp && !op->prec && op->dot)
		str = "";
	ft_putchar_if('0', 1, op->tag && tmp && ((op->width <= mxm(l, op->prec)
				+ 2 * op->tag) || op->zero));
	ft_putchar_if(tr, 1, op->tag && tmp && ((op->width <= mxm(l, op->prec)
				+ 2 * op->tag) || op->zero));
	res = make_fl_d(mxm((int)ft_strlen(str), op->prec)
			+ 2 * (op->tag && tmp), op, !op->minus);
	ft_putchar_if('0', 1, op->tag && tmp && !((op->width <= mxm(l, op->prec)
				+ 2 * op->tag) || op->zero));
	ft_putchar_if(tr, 1, op->tag && tmp && !((op->width <= mxm(l, op->prec)
				+ 2 * op->tag) || op->zero));
	res += put_x_u(str, op, tmp) + make_fl_d(mxm((int)ft_strlen(str),
				op->prec) + 2 * (op->tag && tmp), op, op->minus);
	return (res + 2 * (op->tag && tmp));
}
