/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:42:16 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/28 22:23:25 by geonwkim         ###   ########.fr       */
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
		tab->print_screen = tab->width - tab->precision;
	tab->total_length += tab->print_screen + tab->precision;
	if (tab->dash)
	{
		ft_putstr_fd((char *) str, 1);
		while (tab->print_screen--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (tab->print_screen--)
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
		tab->print_screen = tab->width - len;
	tab->total_length += tab->print_screen + len;
	if (tab->dash)
	{
		ft_putstr_fd("0x", 1);
		ft_putunbr_base_fd(n, 16, 1);
		while (tab->print_screen--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (tab->print_screen--)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("0x", 1);
		ft_putunbr_base_fd(n, 16, 1);
	}
}
