/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:32:10 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/02 17:31:27 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libprintf.h"
#include <stdio.h>

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

int	test_va(const char *str, ...)
{
	va_list	ptr;

	size_t	count_va = count_variatic(str);
	va_start(ptr, count_va);
	for (int i=0; i<count_va; i++)
		printf("%s\n", va_arg(ptr, i));
	va_end(ptr);
}

int	main()
{
	/*
	int	ret_or = printf("Hello %s", "toi");
	printf(" : ");
	fflush(stdout);
	int	ret_ft = ft_printf("Hello");
	printf("\n");
	printf("%i : %i", ret_or, ret_ft);
	*/
	// printf("%zu\n", count_variatic("%s %d %u hello%", SET));
	test_va("%s hey %s hey %s", "one", "two", "three");
}
