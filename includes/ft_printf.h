/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:50:26 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/06 00:07:25 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF
# define LIBPRINTF

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

// Main functions
int	ft_printf(const char *str, ...);

int	ft_putarg_size(const char *ptr, va_list args);

int	ft_putstr_size(char *str);
int	ft_putchar_size(int c);
int	ft_putnbr_size(int n);
int	ft_putptr_size(void *ptr);
int	ft_putunsigned_size(unsigned int n);
int	ft_puthexa_size(int n, char *base);

#endif
