/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:14:22 by alefranc          #+#    #+#             */
/*   Updated: 2021/11/02 21:14:23 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s2 = ft_strdup(s);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s2[i] != '\0')
	{
		s2[i] = f(i, s2[i]);
		i++;
	}
	return (s2);
}
