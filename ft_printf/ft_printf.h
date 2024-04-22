/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iginsaus <iginsaus@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:20:51 by iginsaus          #+#    #+#             */
/*   Updated: 2024/04/09 08:19:29 by iginsaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int	ft_printf(char const *string, ...);
int	ft_putstr(char *s);
int	ft_putnbr(long n);
int	ft_hexnumber(unsigned int n, char *base);
int	ft_address(unsigned long n, char *base);

#endif
