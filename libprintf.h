/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:50:26 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/02 17:59:32 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF
# define LIBPRINTF

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define SET "cspdiuxX%"

typedef struct	s_list
{
	char			c;
	int				(*f)(void *);
	struct s_list	*next;
}				t_list;

int	ft_printf(const char *str, ...);
size_t  count_variatic(const char *str);
int     isinset(char c, const char *set);

#endif
