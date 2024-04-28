/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:42:16 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/28 21:19:44 by geonwkim         ###   ########.fr       */
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
	// if (tab->po)
}