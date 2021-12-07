/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:47:24 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/06 14:47:26 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getnbr_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

int	ft_putnbr_size(int n)
{
	int			size;
	long int	n2;

	size = ft_getnbr_size(n);
	n2 = n;
	if (n2 < 0)
	{
		ft_putchar_fd('-', 1);
		n2 = n2 * -1;
	}
	if (n2 > 9)
		ft_putnbr_size(n2 / 10);
	ft_putchar_fd(n2 % 10 + '0', 1);
	return (size);
}
