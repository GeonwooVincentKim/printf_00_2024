/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:12:24 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/29 14:25:43 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

t_ftprintf	*ft_initialize_tab(t_ftprintf *tab)
{
	tab->pt_screen = 0;
	tab->pad = 0;
	tab->width = 0;
	tab->precision = 0;
	tab->hash_tag = 0;
	tab->zero = 0;
	tab->dash = 0;
	tab->length = 0;
	tab->space = 0;
	tab->plus = 0;
	tab->point = 0;
	tab->upper = 0;
	return (tab);
}

// str[++i] - while the string exists
// &str[i] - print what you need
// i + 1 - start evaluate from the character after the %
// int	ft_printf(const char	*str, ...)
// {
// 	t_ftprintf	tab;
// 	int			ret;

// 	tab.length = 0;
// 	ret = 0;
// 	ft_initialize_tab(&tab);
// 	va_start(tab.args, str);
// 	while (*str)
// 	{
// 		if (*str == '%' && *str++)
// 		{
// 			str = pf_process((char *)str, &tab);
// 			ft_initialize_tab(&tab);
// 		}
// 		else if (++ret)
// 			ft_putchar_fd(*str++, 1);
// 	}
// 	va_end(tab.args);
// 	ret += tab.length;
// 	return (ret);
// }
int	ft_printf(const char	*input, ...)
{
	const char	*save;
	va_list		args;
	int			num;

	num = 0;
	save = ft_strdup(input);
	if (!save)
		return (0);
	va_start(args, input);
	num = ft_count_output(save, args);
	va_end(args);
	free((char *)save);
	return (num);
}

// printf
// specifier (%d, %u, %c...)
// %[flags(+, -, 0)][width].[precision][length][specifier]
static void	pf_subprocess(char c, t_ftprintf *tab)
{
	if (ft_isdigit(c))
	{
		if (tab->point || tab->zero)
			tab->precision = tab->precision * 10 + c - '0';
		else
		{
			if (!tab->width && c == '0')
				tab->zero = 1;
			else
				tab->width = tab->width * 10 + c - '0';
		}
	}
	else if (c == '#')
		tab->hash_tag = 1;
	else if (c == '+')
		tab->plus = 1;
	else if (c == '-')
		tab->dash = 1;
	else if (c == '.')
		tab->point = 1;
	else if (c == ' ')
		tab->space = 1;
}

/*
	c = char
	s = string
	p = pointer
	d = decimal number
	i = integer
	u = 符号なし十進整数
	x = 符号なし十六進整数 (小文字)
	X = 符号なし十六進整数 (大文字)
*/
static char	*pf_process(char *str, t_ftprintf *tab)
{
	while (*str && !ft_strchr("cspdiuxX%", *str))
		pf_subprocess(*str++, tab);
	if (*str == 'c')
		ft_printf_char(tab);
	else if (*str == 's')
		ft_printf_str(tab);
	else if (*str == 'p')
		ft_printf_ptr(tab);
	else if (*str == 'd' || *str == 'i')
		ft_printf_int(tab);
	else if (*str == 'u')
		ft_printf_uint(*str, 10, tab);
	else if (*str == 'x' || *str == 'X')
		ft_printf_uint(*str, 16, tab);
	else if (*str == '%' && ++tab->length)
		ft_putchar_fd(*str, 1);
	return (++str);
}
