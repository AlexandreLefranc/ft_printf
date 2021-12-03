/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:10:50 by alefranc          #+#    #+#             */
/*   Updated: 2021/11/02 21:10:52 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	int		result;
	int		flag_neg;
	int		i;

	result = 0;
	flag_neg = 1;
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-')
	{
		flag_neg = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
	{
		result = result * 10 + (s[i] - 48);
		i++;
	}
	return (result * flag_neg);
}
