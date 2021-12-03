/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:12:24 by alefranc          #+#    #+#             */
/*   Updated: 2021/11/23 17:03:46 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		sub = ft_calloc(1, sizeof(*sub));
	else if (len > ft_strlen(s) - start)
		sub = ft_calloc(ft_strlen(s) - start + 1, sizeof(*sub));
	else
		sub = ft_calloc(len + 1, sizeof(*sub));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (s[i + start] != '\0' && i < len && start < ft_strlen(s))
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
