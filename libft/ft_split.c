/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <alefranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:52:37 by alefranc          #+#    #+#             */
/*   Updated: 2021/11/30 14:13:50 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countwords(char const *s, char c)
{
	size_t	number_of_words;
	size_t	flag_new_word;
	size_t	i;

	flag_new_word = 1;
	number_of_words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag_new_word = 1;
		else
		{
			if (flag_new_word)
			{
				number_of_words++;
				flag_new_word = 0;
			}
		}
		i++;
	}
	return (number_of_words);
}

static void	free_tab(char **tab)
{
	char	**tab_save;

	tab_save = tab;
	while (*tab != NULL)
	{
		free(*tab);
		*tab = NULL;
		tab++;
	}
	free(tab_save);
	tab_save = NULL;
}

static int	fill_tab(char **tab, char const *s, char c)
{
	char	*ptr;
	char	*startp;
	char	*endp;

	ptr = (char *)s;
	while (*ptr != '\0')
	{
		if (*ptr == c)
			ptr++;
		else
		{
			startp = ptr;
			while (*ptr != c && *ptr != '\0')
				ptr++;
			endp = ptr;
			*tab = ft_substr(s, startp - s, endp - startp);
			if (*tab == NULL)
				return (-1);
			tab++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	number_of_words;
	char	**tab;
	int		r;

	if (s == NULL)
		return (NULL);
	number_of_words = countwords(s, c);
	tab = (char **)ft_calloc((number_of_words + 1), sizeof(char *));
	if (tab == NULL)
		return (NULL);
	r = fill_tab(tab, s, c);
	if (r == -1)
	{
		free_tab(tab);
		return (NULL);
	}
	return (tab);
}
