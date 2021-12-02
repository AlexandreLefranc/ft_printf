/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_va2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:53:50 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/02 17:55:45 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int printfln(const char *format, ...)
{
    int result;
    va_list args;

    va_start(args, format);
    result = vprintf(format, args);
    printf("\n");
    va_end(args);

    return result;
}

int main()
{
    int result = printfln("Something \n %d", 10);

    printf("(%d)\n", result);

    return 0;
}
