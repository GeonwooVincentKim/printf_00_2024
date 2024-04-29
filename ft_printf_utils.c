/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:42:16 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/29 13:08:11 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
// va_arg - variadic function
// ft_update_tab - calculate special cases and length
// !tab->dash - if width and not flag, handle right alignment
// write(1, &a, 1) - print clear
// tab->dash - if width and flag, handle left alignment
void	ft_print_char(t_ftprintf *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	ft_update_tab(tab, 1);
	if (tab->width && !tab->dash)
		ft_right_cs(tab, 0);
	if (tab->width && tab->dash)
		ft_left_cs(tab, 0);
}

void	ft_print_str(t_ftprintf *tab)
{
	int			len;
	const char	*str;

	str = va_arg(tab->args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (!tab->point || tab->precision > len)
		tab->precision = len;
	if (tab->width > tab->precision)
		tab->pt_screen = tab->width - tab->precision;
	tab->length += tab->pt_screen + tab->precision;
	if (tab->dash)
	{
		ft_putstr_fd((char *) str, 1);
		while (tab->pt_screen--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (tab->pt_screen--)
			ft_putchar_fd(' ', 1);
		ft_putnstr_fd((char *)str, tab->precision, 1);
	}
}

// 0x = 16進数
// void *pointer argument has to be printed in hexademical format
// (according to ft_printf PDF document)
void	ft_printf_ptr(t_ftprintf *tab)
{
	long long	n;
	int			len;

	n = va_arg(tab->args, long long) + ULONG_MAX + 1;
	len = ft_unumlen(n, 16) + 2;
	if (tab->width > len)
		tab->pt_screen = tab->width - len;
	tab->length += tab->pt_screen + len;
	if (tab->dash)
	{
		ft_putstr_fd("0x", 1);
		ft_putunbr_base_fd(n, 16, 1);
		while (tab->pt_screen--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (tab->pt_screen--)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("0x", 1);
		ft_putunbr_base_fd(n, 16, 1);
	}
}

void	ft_printf_int(t_ftprintf *tab)
{
	int	n;
	int	len;
	int	alen;

	n = va_arg(tab->args, int);
	len = ft_numlen(n, 10);
	alen = ft_unumlen(ft_abs(n), 10);
	test(tab, alen, n, len);
	if (tab->dash)
	{
		ft_putfnbr_base_fd(n, 10, tab, 1);
		while (tab->pt_screen--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (tab->pt_screen--)
			ft_putchar_fd(' ', 1);
		ft_putfnbr_base_fd(n, 10, tab, 1);
	}
}

void	ft_printf_uint(char c, int base, t_ftprintf *tab)
{
	const unsigned int	n = va_arg(tab->args, unsigned int);
	const int			len = ft_unumlen(n, base);

	if (c == 'X')
		tab->upper = 1;
	if (tab->hash_tag && n > 0)
		tab->length += 2;
	if (tab->precision > len)
		tab->pad = tab->precision - len;
	if (tab->width > tab->pad + len)
		tab->pt_screen = tab->width - tab->pad - len;
	tab->length += tab->length + tab->pad + len;
	if (tab->dash)
	{
		ft_putfnbr_base_fd(n, base, tab, 1);
		while (tab->pt_screen--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (tab->pt_screen--)
			ft_putchar_fd(' ', 1);
		ft_putfnbr_base_fd(n, base, tab, 1);
	}
}
