/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_test_123.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:25:56 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/29 14:27:27 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_count_output(const char *save, va_list args)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (save[i])
	{
		if (save[i] == '%')
		{
			i++;
			c += ft_treat_something(save[i], args);
		}
		else
		{
			ft_putchar_fd(save[i], 1);
			c++;
		}
		i++;
		if (!save[i])
			return (c);
	}
	return (c);
}

int	ft_treat_something(int c, va_list args)
{
	int	n;

	n = 0;
	if (c == 'c')
	n = ft_treat_char(va_arg(args, int));
	else if (c == 's')
	n = ft_treat_string(va_arg(args, char *));
	else if (c == 'p')
	n = ft_treat_point((unsigned long long)va_arg(args, void *));
	else if (c == 'd' || c == 'i')
	n = ft_treat_int(va_arg(args, int));
	else if (c == 'u')
	n = ft_treat_uint((unsigned long long)va_arg(args, unsigned long long));
	else if (c == 'x')
	n = ft_treat_hexa(va_arg(args, unsigned int), 1);
	else if (c == 'X')
	n = ft_treat_hexa(va_arg(args, unsigned int), 2);
	else if (c == '%')
	n = ft_putstr_count("%");
	return (n);
}

static char	*change_base(unsigned long long us, int b, char *r, int c)
{
	while (us != 0)
	{
		if ((us % b) < 10)
			r[c - 1] = (us % b) + 48;
		else
			r[c - 1] = (us % b) + 55;
		us /= b;
		c--;
	}
	return (r);
}

char	*ft_point_base(unsigned long long point, int base)
{
	char				*rtn;
	unsigned long long	us;
	int					count;

	count = 0;
	us = point;
	if (point == 0)
		return (ft_strdup("0"));
	while (point != 0)
	{
		point = point / base;
		count++;
	}
	rtn = ft_calloc(count + 1, sizeof(char));
	if (!rtn)
		return (0);
	rtn = change_base(us, base, rtn, count);
	return (rtn);
}
