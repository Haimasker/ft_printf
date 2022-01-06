/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:23:16 by lumfred           #+#    #+#             */
/*   Updated: 2021/11/28 14:05:23 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_flags(struct s_flags *op)
{
	op->width = 0;
	op->zero = 0;
	op->minus = 0;
	op->plus = 0;
	op->dot = 0;
	op->prec = 0;
	op->tag = 0;
	op->plus_space = '+';
}

void	make_star(va_list arg, struct s_flags *op, int make)
{
	int	w;

	if (!make)
		return ;
	w = va_arg(arg, int);
	op->minus |= (int)((w < 0) && (!op->dot));
	if (w < 0 && !op->dot)
		op->width = w * (-1);
	if (w < 0 && op->dot)
		op->dot = 0;
	if (op->dot && w >= 0)
		op->prec = w;
	if (!op->dot && w >= 0)
		op->width = w;
}

int	process_flags(va_list arg, char *tr, struct s_flags *op)
{
	int	res;

	res = 0;
	while (!ft_strchr("csdi%uxXp", *tr)
		&& ft_strchr("0123456789. +-#*", *tr) && (++res))
	{
		op->minus |= (int)(*tr == '-');
		op->dot |= (int)(*tr == '.');
		op->tag |= (int)(*tr == '#');
		if (*tr == '+')
			op->plus_space = '+';
		if (*tr == ' ' && !op->plus)
			op->plus_space = ' ';
		op->plus |= (int)((*tr == '+') || (*tr == ' '));
		if ((*tr != '0' || op->width) && !op->dot && ft_isdigit(*tr))
			op->width = op->width * 10 + (*tr - '0');
		op->zero |= (*tr == '0' && !op->width && !op->dot && ft_isdigit(*tr));
		if (ft_isdigit(*tr))
			op->prec = (op->prec * 10 + (*tr - '0')) * op->dot
				| op->prec * !op->dot;
		make_star(arg, op, (int)(*tr++ == '*'));
	}
	op->zero &= ((op->minus - 1) / (-1));
	return (res);
}

int	make_fl_d(int space, struct s_flags *op, int make)
{
	int		res;
	int		width;
	char	ch;

	res = 0;
	if (make)
	{
		width = op->width - space;
		if (op->zero)
			ch = '0';
		else
			ch = ' ';
		while (width-- > 0)
		{
			ft_putchar_fd(ch, 1);
			res++;
		}
	}
	return (res);
}

int	make_fl_s(int space, struct s_flags *op, int make)
{
	int		res;
	int		width;
	char	ch;

	if (op->zero)
		ch = '0';
	else
		ch = ' ';
	res = 0;
	if (make)
	{
		width = op->width - space;
		while (width-- > 0)
		{
			ft_putchar_fd(ch, 1);
			res++;
		}
	}
	return (res);
}
