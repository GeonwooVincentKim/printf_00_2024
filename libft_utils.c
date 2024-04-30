/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:01:27 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/30 15:18:47 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static void	reset(t_ftprintf *tab)
{
	tab->hash_tag = 0;
	tab->space = 0;
	tab->plus = 0;
}

void	ft_putnstr_fd(char *s, int len, int fd)
{
	write(fd, s, len);
}

int	ft_unumlen(unsigned long long n, int base)
{
	if (!(n / base))
		return (1);
	return (1 + ft_unumlen(n / base, base));
}

void	ft_putunbr_base_fd(unsigned long long n, int base, int fd)
{
	const char	*digits = "0123456789abcdef";

	if (n / base)
		ft_putunbr_base_fd(n / base, base, fd);
	ft_putchar_fd(digits[n % base], fd);
}

void	ft_putfnbr_base_fd(long long n, int base, t_ftprintf *tab, int fd)
{
	int			sign;
	const char	*digits = "0123456789abcdef";

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	else if (n > 0 && tab->hash_tag && tab->upper)
		ft_putstr_fd("0X", 1);
	else if (n > 0 && tab->hash_tag && !tab->upper)
		ft_putstr_fd("0x", 1);
	else if (tab->space)
		ft_putchar_fd(' ', fd);
	else if (tab->plus)
		ft_putchar_fd('+', fd);
	if (tab->upper)
		digits = "0123456789ABCDEF";
	while (tab->pad-- > 0)
		ft_putchar_fd('0', fd);
	reset(tab);
	if (n / base)
		ft_putfnbr_base_fd(n / base * sign, base, tab, fd);
	ft_putchar_fd(digits[n % base * sign], fd);
}
