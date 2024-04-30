/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_non_primitive.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:40:34 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/30 15:51:54 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_point(unsigned long long point)
{
	char	*p;
	int		n;

	p = ft_tolower_all(ft_point_base(point, 16));
	n = ft_putstr_count("0x");
	n += ft_putstr_count(p);
	free(p);
	return (n);
}

int	ft_treat_string(char *str)
{
	int	n;

	if (str == NULL)
		str = "(null)";
	n = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (n);
}
