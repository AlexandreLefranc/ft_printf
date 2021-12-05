/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:50:26 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/06 00:07:25 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF
# define LIBPRINTF

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

# define SET "cspdiuxX%"

int	ft_printf(const char *str, ...);

int ft_isbasevalid(char *base);

#endif
