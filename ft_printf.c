/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:32:35 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/30 15:33:41 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
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
