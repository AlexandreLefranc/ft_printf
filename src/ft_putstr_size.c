/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:14:55 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/06 17:14:57 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
