/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumfred <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:33:14 by lumfred           #+#    #+#             */
/*   Updated: 2021/11/28 14:12:07 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

struct s_flags
{
	int		width;
	int		zero;
	int		minus;
	int		plus;
	int		dot;
	int		prec;
	int		tag;
	char	plus_space;
};

int		ft_printf(const char *string, ...);
char	*convert_num(unsigned long long num, int base, char flag);
int		put_param(char traverse, va_list arg, struct s_flags *op);

void	reset_flags(struct s_flags *op);
void	make_star(va_list arg, struct s_flags *op, int make);
int		process_flags(va_list arg, char *tr, struct s_flags *op);
int		make_fl_d(int space, struct s_flags *op, int make);
int		make_fl_s(int space, struct s_flags *op, int make);

int		process_c(va_list arg, struct s_flags *op);
int		process_s(va_list arg, struct s_flags *op);
int		process_d_i(char traverse, va_list arg, struct s_flags *op);
int		process_u(char traverse, va_list arg, struct s_flags *op);
int		process_x(char traverse, va_list arg, struct s_flags *op);
int		process_p(char traverse, va_list arg, struct s_flags *op);

int		put_s(char *str, struct s_flags *op);
int		put_d_i(char *str, struct s_flags *op, int minus, int tmp);
int		put_x_u(char *str, struct s_flags *op, int tmp);

void	ft_putchar_if(char c, int fd, int state);
int		process_min_int(struct s_flags *op);
int		mxm(int a, int b);
int		mnm(int a, int b);

#endif
