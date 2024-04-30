/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:34:05 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/30 15:55:07 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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
