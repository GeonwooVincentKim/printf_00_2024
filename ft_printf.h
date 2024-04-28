/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:12:10 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/28 21:03:47 by geonwkim         ###   ########.fr       */
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
	dash - (include minus)
	percent - %
	space - space flag ' '
	hash tag - #
*/
typedef struct s_ftprintf
{
	va_list		args;
	int			width;
	int			precision;
	int			zero;
	int			point;
	int			dash;
	int			total_length;
	int			sign;
	int			is_zero;
	int			percent;
	int			space;
	int			hash_tag;
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
// ft_printf_utils.c
void		ft_print_char(t_ftprintf *tab);


#endif
