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

#include "libftprintf.h"

// clangc ft_printf.c -Llibft/ -lft && ./a.out
#include <stdio.h>

int	ft_isbasevalid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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
	if (n2 == 0)
		blocks++;
	while (n2 != 0)
	{
		blocks++;
		n2 = n2 / ft_strlen(base);
	}
	out = (char *)ft_calloc(blocks + 1, sizeof(*out));
	if (out == NULL)
		return (NULL);
	out[blocks] = '\0';
	if (n == 0)
		out[blocks - 1] = base[n % ft_strlen(base)];
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
	else if (*ptr == 's')
		r += ft_putstr_size(va_arg(args, char *));
	else if (*ptr == 'd' || *ptr == 'i')
		r += ft_putnbr_size(va_arg(args, int));
	else if (*ptr == 'c')
		r += ft_putchar_size(va_arg(args, int));
	else if (*ptr == 'p')
		r += ft_putptr_size(va_arg(args, void *));
	else if (*ptr == 'u')
		;
	else if (*ptr == 'x')
		;
	else if (*ptr == 'X')
		;
	else 
		r += ft_putchar_size(*ptr);
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
	{
		char s[] = "yo";
		int res = ft_printf("Yo %s, t'as %dans%% %d bie%c ptr=%p\n", "Bob", 5, 13, 's', s);
		int res2 =   printf("Yo %s, t'as %dans%% %d bie%c ptr=%p\n", "Bob", 5, 13, 's', s);
		printf("%d : %d\n\n", res, res2);
		fflush(stdout);
	}
	{
		char s[] = "yo";
		printf("%p | %s\n\n", s, ft_itoa_llu_base((unsigned long long)s, "0123456789abcdef"));
		fflush(stdout);
	}
	{
		int res = ft_printf("%");
		(void)res;
//		int res2 =   printf("%");
//		printf("%d : %d\n\n", res, res2);
		fflush(stdout);
	}
	{
		int res = ft_printf("");
		int res2 =   printf("");
		printf("%d : %d\n\n", res, res2);
		fflush(stdout);
	}
	{
		int res = ft_printf("%d, %i, %s, %c, %p, %%\n", 42, 42, "42", 42, NULL);
		int res2 =   printf("%d, %i, %s, %c, %p, %%\n", 42, 42, "42", 42, NULL);
		printf("%d : %d\n\n", res, res2);
		fflush(stdout);
	}
	{
		int res = ft_printf("%x, %X\n", 42, 42);
		int res2 =   printf("%x, %X\n", 42, 42);
		printf("%d : %d\n\n", res, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%c\n==================\n");
		int	res1 = ft_printf("%c", 't');
		printf(" : ");
		int	res2 =    printf("%c", 't');
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%s\n==================\n");
		int	res1 = ft_printf("%s", "Hello");
		printf(" : ");
		int	res2 =    printf("%s", "Hello");
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%i\n==================\n");
		int	res1 = ft_printf("%i", -42);
		printf(" : ");
		int	res2 =    printf("%i", -42);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%d\n==================\n");
		int	res1 = ft_printf("%d", -42);
		printf(" : ");
		int	res2 =    printf("%d", -42);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%p\n==================\n");
		char p[1];
		int	res1 = ft_printf("%p", p);
		printf(" : ");
		int	res2 =    printf("%p", p);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%%%\n==================\n");
		int	res1 = ft_printf("%%");
		printf(" : ");
		int	res2 =    printf("%%");
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
	}
	{
		printf("\n==================\n%%x\n==================\n");
		int	res1 = ft_printf("%d", 0);
		printf(" : ");
		int	res2 =    printf("%x", 0);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%d", 42);
		printf(" : ");
		res2 =    printf("%x", 42);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%d", -42);
		printf(" : ");
		res2 =    printf("%x", -42);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

		res1 = ft_printf("%d", 2147483647);
		printf(" : ");
		res2 =    printf("%x", 2147483647);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);
		
		res1 = ft_printf("%d", -2147483648);
		printf(" : ");
		res2 =    printf("%x", (unsigned int)-2147483648);
		printf("\n%d : %d\n\n", res1, res2);
		fflush(stdout);

	}

}
