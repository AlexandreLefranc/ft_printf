/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:50:26 by alefranc          #+#    #+#             */
/*   Updated: 2021/12/03 17:25:38 by alefranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF
# define LIBPRINTF

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define SET "cspdiuxX%"

int	ft_printf(const char *str, ...);

#endif
