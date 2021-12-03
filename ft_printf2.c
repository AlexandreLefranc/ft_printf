/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:19:30 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/03 17:25:10 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include "libft/libft.h"

// gccc ft_printf2.c -Llibft/ -lft && ./a.out | cat -e
#include <stdio.h>

int	ft_putstr_size(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_putchar_size(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putnbr_size(int c)
{
	char	*tmp;
	int		r;

	tmp = ft_itoa(c);
	if (tmp == NULL)
		return (-1);
	r = ft_putstr_size(tmp);
	free(tmp);
	return (r);
}

char	*ft_itoa_llu_base(unsigned long long n, char *base)
{
	char				*out;
	int					blocks;
	unsigned long long	n2;

	n2 = n;
	blocks = 0;
	while (n2 != 0)
	{
		blocks++;
		n2 = n2 / ft_strlen(base);
	}
	out = (char *)ft_calloc(blocks + 1, sizeof(*out));
	if (out == NULL)
		return (NULL);
	out[blocks] = '\0';
	while (n > 0)
	{
		out[blocks - 1] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
		blocks--;
	}
	return (out);
}

int	ft_putptr_size(void *ptr)
{
	char	*tmp;
	int		r;

	r = 0;
	r += ft_putstr_size("0x");
	tmp = ft_itoa_llu_base((unsigned long long)ptr, "0123456789abcdef");
	if (tmp == NULL)
		return (-1);
	r += ft_putstr_size(tmp);
	free(tmp);
	return (r);
}

int	ft_putarg_size(const char *ptr, va_list args)
{
	int		r;

	r = 0;
	if (*ptr == '%')
		r += ft_putstr_size("%");
	if (*ptr == 's')
		r += ft_putstr_size(va_arg(args, char *));
	if (*ptr == 'd' || *ptr == 'i')
		r += ft_putnbr_size(va_arg(args, int));
	if (*ptr == 'c')
		r += ft_putchar_size(va_arg(args, int));
	if (*ptr == 'p')
		r += ft_putptr_size(va_arg(args, void *));
	if (*ptr == 'u')
		;
	if (*ptr == 'x')
		;
	if (*ptr == 'X')
		;
	return (r);
}

int	_ft_printf(const char *format, va_list args)
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

int main()
{
	char s[] = "yo";
    int res = ft_printf("Yo %s, t'as %dans%% %d bie%c ptr=%p\n", "Bob", 5, 13, 's', s);
	int res2 =   printf("Yo %s, t'as %dans%% %d bie%c ptr=%p\n", "Bob", 5, 13, 's', s);

    printf("%d : %d\n", res, res2);

	printf("%p | %s\n", s, ft_itoa_llu_base((unsigned long long)s, "0123456789abcdef"));

}
