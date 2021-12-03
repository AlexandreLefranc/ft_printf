/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:21:15 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/02 21:22:29 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int	test_printf(const char *str, ...)
{
	va_list	args;
	va_start(args, str);
	printf("%s\n", va_arg(args, char *));
	printf("%d\n", va_arg(args, int));
	printf("%d\n", va_arg(args, int));
	va_end(args);
	return (0);
}

int	main()
{
	int	res = test_printf("Yo %s, t'as %d ans et %% %d billes\n", "Bob", 5, 13);

	printf("%d\n", res);
}
