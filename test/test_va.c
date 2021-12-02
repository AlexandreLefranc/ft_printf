/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_va.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:36:19 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/02 17:45:58 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#define SET "cspdiuxX%"

int     isinset(char c, const char *set)
{
    while (*set != '\0')
    {
        if (c == *set)
            return (1);
        set++;
    }
    return (0);
}

size_t  count_variatic(const char *str)
{
    size_t  count;

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

void	_test_va(int count_va, ...)
{
	va_list	ptr;
	va_start(ptr, count_va);
	for (int i=0; i<count_va; i++)
		printf("%s\n", va_arg(ptr, char *));
	va_end(ptr);
}

void	test_va(const char *str, ...)
{
	int	count_va = (int)count_variatic(str);
	_test_va(count_va, ...);
}

int	main()
{
	test_va("%s hey %s hey %s", "one", "two", "three");
}
