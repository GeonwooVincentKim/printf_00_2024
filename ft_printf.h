/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:12:10 by geonwkim          #+#    #+#             */
/*   Updated: 2024/04/28 13:49:55 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

// ft_printf structs
typedef struct s_ftprintf
{
	va_list		args;
	int			width;
	int			precision;
	int			zero;
	int			point;
	int			dash;
	int			total_length;
	int			sign;
	int			is_zero;
	int			percent;
	int			space;
}	t_ftprintf;

// ft_printf_initialize
t_ftprintf	*ft_initialize_tab(t_ftprintf *tab);

// ft_printf
int			ft_printf(const char	*str, ...);

// 

#endif
