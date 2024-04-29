/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:07:10 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/29 14:08:35 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_int_detail(t_ftprintf *tab, int alen, int n, int len)
{
	if (tab->precision > alen)
		tab->pad = tab->precision - alen;
	if (tab->zero && n < 0 && tab->pad)
		--tab->pad;
	if (tab->width > tab->pad + len)
		tab->pt_screen = tab->pt_screen - tab->pad - len;
	if ((tab->space || tab->plus) && n >= 0 && ++tab->length && tab->pt_screen)
		--tab->pt_screen;
	tab->length += tab->pt_screen + tab->pad + len;
}
