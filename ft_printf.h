/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:12:10 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/30 15:52:11 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

// ft_printf structs
/*
	args - print out arg
	point - .
	precision
	- precise the type (such as floating point)
	- 浮動小数点 (1.0000000000000007)
	- example) %.3d (12) -> 012
	dash - (include minus)
	percent - %
	space - space flag ' '
	hash tag - #
	length - length of string
	pad
	- padding
	- example: %010s
*/
// typedef struct s_ftprintf
// {
// 	va_list		args;
// 	int			pt_screen;
// 	int			pad;
// 	int			width;
// 	int			precision;
// 	int			hash_tag;
// 	int			zero;
// 	int			dash;
// 	int			length;
// 	int			space;
// 	int			plus;
// 	int			point;
// 	int			upper;
// }	t_ftprintf;

// ft_printf.c
// t_ftprintf	*ft_initialize_tab(t_ftprintf *tab);
// int			ft_printf(const char	*str, ...);

/*
	va_list args; -> 宣言
	va_start(args, format)
	-> 初期化、name of variable args, last know element

	va_arg(args, int)
	-> to move to the next variable in memory
	-> name of the variable args (引数), type of the variable (変数型)

	va_end(args)
	-> va実行が終わったら、この関数を閉める
*/
// ft_printf_utils.c (part 1)
// void		ft_printf_char(t_ftprintf *tab);
// void		ft_printf_str(t_ftprintf *tab);
// void		ft_printf_ptr(t_ftprintf *tab);
// void		test(t_ftprintf *tab, int alen, int n, int len);
// int			ft_printf_int(int i);
// // void		ft_printf_int(t_ftprintf *tab);
// int			ft_print_int(int n, t_ftprintf *tab);
// int			ft_print_integer(char *str, int n, t_ftprintf tab);
// int			ft_print_i(char *str, int n, t_ftprintf tab);
// void		ft_printf_unit(char c, int base, t_ftprintf *tab);

// ft_printf_utils.c (part 2)
// u -> unsigned
// void		ft_putnstr_fd(char *s, int len, int fd);
// int			ft_unumlen(unsigned long long n, int base);
// void		ft_putunbr_base_fd(unsigned long long n, int base, int fd);
// void		ft_putfnbr_base_fd(long long n, int base, t_ftprintf *fmt, int fd);

// test area
// int			ft_count_output(const char *save, va_list args);
// int			ft_treat_something(int c, va_list args);
// char		*ft_point_base(unsigned long long point, int base);
// char		*ft_tolower_all(char *c);
// int			ft_treat_char(char c);
// int			ft_treat_string(char *str);
// int			ft_treat_point(unsigned long long point);
// int			ft_treat_int(int i);
// int			ft_treat_uint(unsigned long long uint);
// int			ft_treat_hexa(unsigned int i, int f);
// int			ft_printf(const char	*input, ...);
// int			ft_putstr_count(char *c);

// ft_printf.c
int		ft_printf(const char *input, ...);
int		ft_count_output(const char *save, va_list args);
int		ft_treat_something(int c, va_list args);

// ft_printf_utils.c
int		ft_putstr_count(char *c);
char	*ft_tolower_all(char *c);

// ft_base.c
char	*ft_point_base(unsigned long long point, int base);

// ft_treat_decimal.c
int		ft_treat_uint(unsigned long long uint);
int		ft_treat_hexa(unsigned int i, int f);

// ft_treat_non_primitive.c
int		ft_treat_point(unsigned long long point);
int		ft_treat_string(char *str);

// ft_treat_primitive.c
int		ft_treat_char(char c);
int		ft_treat_int(int i);

#endif
