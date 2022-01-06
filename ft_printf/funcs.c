/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:32:37 by lumfred           #+#    #+#             */
/*   Updated: 2021/11/29 10:54:24 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mxm(int a, int b)
{
	return ((b & ((a - b) >> 31)) | (a & (~(a - b) >> 31)));
}

int	mnm(int a, int b)
{
	return ((a & ((a - b) >> 31)) | (b & (~(a - b) >> 31)));
}

void	ft_putchar_if(char c, int fd, int state)
{
	if (state)
		write(fd, &c, 1);
}

int	process_min_int(struct s_flags *op)
{
	int		res;
	char	*str;

	str = ft_strdup("2147483648");
	op->zero &= !(op->dot && (op->prec < op->width));
	ft_putchar_if('-', 1, op->zero);
	res = make_fl_d(11, op, !op->minus);
	ft_putchar_if('-', 1, !op->zero);
	ft_putstr_fd(str, 1);
	res += make_fl_d(11, op, op->minus);
	free(str);
	return (res + 11);
}
