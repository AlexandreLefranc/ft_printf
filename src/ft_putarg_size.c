/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarg_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:47:13 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/06 14:47:15 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putarg_size(const char *ptr, va_list args)
{
	int		r;

	r = 0;
	if (*ptr == '%')
		r += ft_putstr_size("%");
	else if (*ptr == 's')
		r += ft_putstr_size(va_arg(args, char *));
	else if (*ptr == 'd' || *ptr == 'i')
		r += ft_putnbr_size(va_arg(args, int));
	else if (*ptr == 'c')
		r += ft_putchar_size(va_arg(args, int));
	else if (*ptr == 'p')
		r += ft_putptr_size(va_arg(args, void *));
	else if (*ptr == 'u')
		r += ft_putunsigned_size(va_arg(args, unsigned int));
	else if (*ptr == 'x')
		r += ft_puthexa_size(va_arg(args, int), "0123456789abcdef");
	else if (*ptr == 'X')
		r += ft_puthexa_size(va_arg(args, int), "0123456789ABCDEF");
	else
		r += ft_putchar_size(*ptr);
	return (r);
}
