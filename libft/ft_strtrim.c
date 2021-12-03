/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:12:14 by alefranc          #+#    #+#             */
/*   Updated: 2021/11/24 16:40:04 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr1;
	char	*ptr2;
	char	*trimmed;
	int		i;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (ft_isinset(s1[i], set))
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	ptr1 = (char *)s1 + i;
	while (s1[i] != '\0')
	{
		if (!ft_isinset(s1[i], set))
			ptr2 = (char *)s1 + i;
		i++;
	}
	trimmed = ft_substr(s1, ptr1 - s1, ptr2 - ptr1 + 1);
	if (trimmed == NULL)
		return (NULL);
	return (trimmed);
}
