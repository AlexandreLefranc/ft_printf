/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:03:45 by alefranc          #+#    #+#             */
/*   Updated: 2021/11/09 18:31:43 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_n_len(int n)
{
	size_t	count;

	if (n == 0)
		return ((size_t)1);
	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static void	fill_s(char *s, int n, size_t n_len)
{
	size_t		i;
	size_t		stop;

	stop = 0;
	i = n_len;
	s[n_len] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		stop = 1;
	}
	while (i > stop)
	{
		if (stop == 0)
			s[i - 1] = n % 10 + '0';
		else if (stop == 1)
			s[i - 1] = n % 10 * -1 + '0';
		n = n / 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	size_t	n_len;
	char	*s;

	n_len = count_n_len(n);
	s = (char *)ft_calloc(n_len + 1, sizeof(char));
	if (s == NULL)
		return (NULL);
	fill_s(s, n, n_len);
	return (s);
}
