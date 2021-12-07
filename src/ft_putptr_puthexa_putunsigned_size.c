/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_puthexa_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:47:37 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/06 14:47:53 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getllu_size_base(unsigned long long llu, char *base)
{
	int	r;

	r = 0;
	if (llu == 0)
		return (1);
	while (llu != 0)
	{
		r++;
		llu = llu / ft_strlen(base);
	}
	return (r);
}

static void	ft_putnbr_llu_base(unsigned long long llu, char *base)
{
	if (llu > ft_strlen(base) - 1)
		ft_putnbr_llu_base(llu / ft_strlen(base), base);
	ft_putchar_fd(base[llu % ft_strlen(base)], 1);
}

int	ft_putptr_size(void *ptr)
{
	int					r;
	unsigned long long	ptr_llu;

	ptr_llu = (unsigned long long)ptr;
	r = 0;
	r += ft_getllu_size_base(ptr_llu, "0123456789abcdef");
	r += ft_putstr_size("0x");
	ft_putnbr_llu_base(ptr_llu, "0123456789abcdef");
	return (r);
}

int	ft_putunsigned_size(unsigned int n)
{
	int				r;
	unsigned int	n2;

	n2 = n;
	r = 0;
	r += ft_getllu_size_base(n2, "0123456789");
	ft_putnbr_llu_base(n2, "0123456789");
	return (r);
}

int	ft_puthexa_size(int n, char *base)
{
	int				r;
	unsigned int	n2;

	n2 = n;
	r = 0;
	r += ft_getllu_size_base(n2, base);
	ft_putnbr_llu_base(n2, base);
	return (r);
}
