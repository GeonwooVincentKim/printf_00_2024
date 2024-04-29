/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_test_789.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:29:03 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/29 14:30:25 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_int(int i)
{
	char	*str;
	int		n;

	str = ft_itoa(i);
	n = ft_putstr_count(str);
	free(str);
	return (n);
}

static int	ft_put_unbr_count(unsigned long long n)
{
	char				str;
	unsigned long long	tmp;
	size_t				t;

	tmp = n;
	t = 0;
	while (9 < tmp)
	{
		tmp = tmp / 10;
		t++;
	}
	if (9 < n)
		ft_put_unbr_count(n / 10);
	str = '0' + n % 10;
	write(1, &str, 1);
	return (t + 1);
}

int	ft_treat_uint(unsigned long long uint)
{
	int	n;

	n = 0;
	n = ft_put_unbr_count(uint, 1);
	return (n);
}

int	ft_treat_hexa(unsigned int i, int f)
{
	char	*hex;
	int		n;

	if (!i)
		i = 0;
	hex = ft_point_base((unsigned long long)i, 16);
	if (f == 1)
		hex = ft_tolower_all(hex);
	n = ft_putstr_count(hex);
	free(hex);
	return (n);
}
