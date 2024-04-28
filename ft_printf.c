/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:12:24 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/28 13:51:12 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

t_ftprintf	*ft_initialize_tab(t_ftprintf *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->sign = 0;
	tab->total_length = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->percent = 0;
	tab->space = 0;
	return (tab);
}

int	ft_printf(const char	*str, ...)
{
	t_ftprintf	*tab;

	tab = (t_ftprintf *)malloc(sizeof(t_ftprintf));
	if (!tab)
		return (-1);
	ft_initialize_tab(tab);
}
