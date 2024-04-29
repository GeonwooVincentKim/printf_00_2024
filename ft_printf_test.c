/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:32:35 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/29 14:33:52 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char	*input, ...)
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
