/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:19:30 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/06 02:45:52 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_ft_printf(const char *format, va_list args)
{
	int		r;
	char	*start;
	char	*oldptr;
	char	*ptr;

	r = 0;
	start = ft_strdup(format);
	oldptr = start;
	ptr = ft_strchr(start, '%');
	while (ptr != NULL)
	{
		*ptr = '\0';
		r += ft_putstr_size(oldptr);
		r += ft_putarg_size(ptr + 1, args);
		oldptr = ptr + 2;
		ptr = ft_strchr(ptr + 2, '%');
	}
	r += ft_putstr_size(oldptr);
	free(start);
	return (r);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		r;

	r = 0;
	va_start(args, format);
	r += _ft_printf(format, args);
	va_end(args);
	return (r);
}
