/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:12:53 by alefranc          #+#    #+#             */
/*   Updated: 2021/11/02 21:12:55 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	ssize_t	i;
	char	*ptr;
	char	c2;

	c2 = (char)c;
	ptr = (char *)s;
	i = ft_strlen(s);
	while (i > -1)
	{
		if (ptr[i] == c2)
			return (&ptr[i]);
		i--;
	}
	return (NULL);
}
