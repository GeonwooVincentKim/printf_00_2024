/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:12:10 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/28 22:07:30 by geonwkim         ###   ########.fr       */
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
	dash - (include minus)
	percent - %
	space - space flag ' '
	hash tag - #
	total_length - length of string
	pad
	- padding
	- example: %010s
*/
typedef struct s_ftprintf
{
	va_list		args;
	int			print_screen;
	int			pad;
	int			width;
	int			precision;
	int			hash_tag;
	int			zero;
	int			dash;
	int			total_length;
	int			space;
	int			plus;
	int			point;
	int			upper;
}	t_ftprintf;

// ft_printf.c
t_ftprintf	*ft_initialize_tab(t_ftprintf *tab);
int			ft_printf(const char	*str, ...);

/*
	va_list args; -> 宣言
	va_start(args, format)
	-> 初期化、name of variable args, last know element

	va_arg(args, int)
	-> to move to the next variable in memory
	-> name of the variable args, type of the variable

	va_end(args)
	-> va実行が終わったら、この関数を閉める
*/
// ft_printf_utils.c (part 1)
void		ft_printf_char(t_ftprintf *tab);
void		ft_printf_str(t_ftprintf *tab);
void		ft_printf_ptr(t_ftprintf *tab);
void		ft_printf_int(t_ftprintf *tab);
void		ft_printf_unit(char c, int base, t_ftprintf *fmt);

// ft_printf_utils.c (part 2)
void		ft_putnstr_fd(char *s, int len, int fd);
int			ft_unumlen(unsigned long long n, int base);
void		ft_putunbr_base_fd(unsigned long long n, int base, int fd);
void		ft_putfnbr_base_fd(long long n, int base, t_ftprintf *fmt, int fd);

#endif
