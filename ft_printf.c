/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:54:21 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/02 17:25:14 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

int		isinset(char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

size_t	count_variatic(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == '%' && isinset(*(str + 1), SET))
		{
			str++;
			count++;
		}
		str++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	count_variatic;

	if (isvalidstring(str))
	{
		// check if % is followed by char in set
		// check if % is not the last character
		// check if str is not NULL
		//
	}
	(void)count_variatic;


	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_putchar_fd(str[i]);
		/* else */
		/* { */
		/* 	list2 = list; */
		/* 	while (list2 != NULL) */
		/* 	{ */
		/* 		if (list2->c == str[i + 1]) */
		/* 		{ */
		/* 			list2->f(); */
		/* 			break */
		/* 		} */
		/* 		list2 = list2->next */
		/* 	} */
		/* 	if (list2 == NULL) */

		/* } */
		i++;
	}
	return (i);
}
