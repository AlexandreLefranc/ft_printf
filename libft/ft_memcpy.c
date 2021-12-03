/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:16:20 by alefranc          #+#    #+#             */
/*   Updated: 2021/11/02 21:16:22 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src2;

	if (dest == NULL && src == NULL)
		return (dest);
	src2 = (char *)src;
	i = 0;
	while (i < n)
	{
		ft_memset(dest + i, src2[i], 1);
		i++;
	}
	return (dest);
}
