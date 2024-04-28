/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:12:24 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/28 21:16:53 by geonwkim         ###   ########.fr       */
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
	tab->hash_tag = 0;
	return (tab);
}

// str[++i] - while the string exists
// &str[i] - print what you need
// i + 1 - start evaluate from the character after the %
int	ft_printf(const char	*str, ...)
{
	t_ftprintf	*tab;
	int			i;
	int			ret;

	tab = (t_ftprintf *)malloc(sizeof(t_ftprintf));
	if (!tab)
		return (-1);
	ft_initialize_tab(tab);
	va_start(tab->args, str);
	i = -1;
	ret = 0;
	while (str[++i])
	{
		if (str[i] == '%')
			i = ft_eval_format(tab, str, i + 1);
		else
			ret += write(1, &str[i], 1);
	}
	va_end(tab->args);
	ret += tab->total_length;
	free(tab);
	return (ret);
}

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
	else if (c == '-')
		tab->dash = 1;
	else if (c == '.')
		tab->point = 1;
	else if (c == '%')
		tab->percent = 1;
	else if (c == ' ')
		tab->space = 1;
}
