/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iginsaus <iginsaus@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 07:56:50 by iginsaus          #+#    #+#             */
/*   Updated: 2024/04/09 08:25:19 by iginsaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_forming(va_list arg, char format)
{
	if (format == 'c')
		return (write(1, &(char){va_arg(arg, int)}, 1));
	if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (format == 'u')
		return (ft_putnbr(va_arg(arg, unsigned int)));
	if (format == 'p')
	{
		return (write(1, "0x", 2) + ft_address(va_arg(arg, unsigned long),
				"0123456789abcdef"));
	}
	if (format == 'x')
		return (ft_hexnumber(va_arg(arg, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (ft_hexnumber(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	if (format == '%')
		return (write(1, &format, 1));
	return (0);
}

int	ft_printf(char const *string, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			len += ft_forming(arg, string[i]);
		}
		else
			len += write(1, &string[i], 1);
		if (string[i] != '\0')
			i++;
	}
	va_end(arg);
	return (len);
}
/*
int	main(void)
{
// Characters.
	printf("\n\nT E S T I N G   C H A R A C T E R S\n\n");
	char c_m = 'A';
	char c_p = 'z';
	printf("%c (printf): %c\n", c_m, c_m);
	ft_printf("%c (ft_printf): %c\n", c_m, c_m);
	printf("%c (printf): %c\n", c_p, c_p);
	ft_printf("%c (ft_printf): %c\n", c_p, c_p);
	printf("\nNow ASCII printable with printf and ft_printf\n");
	int j = 32;
	while (j <= 126)
	{
		printf("%c", j);
		ft_printf("%c",j);
		j++;
	}
// Strings.
	printf("\n\nT E S T I N G   S T R I N G S\n\n");
	char *s_empty = "";
	char *s_null = NULL;
	printf("%s (empty printf): %s\n", "String", s_empty);
	ft_printf("%s (empty ft_printf): %s\n", "String", s_empty);
	printf("%s (null printf): %s\n", "String", s_null);
	ft_printf("%s (null ft_printf): %s\n", "String", s_null);
	char *s_example = "Normal String to test";
	printf("%s (test printf): %s\n", "String", s_example);
	ft_printf("%s (test ft_printf): %s\n", "String", s_example);
// Integers.
	printf("\n\nT E S T I N G   I N T E G E R S with %%d & %%u\n\n");
	int d_n = -123;
	int d_p = 12345;
	unsigned int u_m = 65535;
	printf("(negative printf): %d\n", d_n);
	ft_printf("(negative ft_printf): %d\n", d_n);
	printf("(positive printf): %d\n", d_p);
	ft_printf("(positive ft_printf): %d\n", d_p);
	printf("(unsigned printf): %u\n", u_m);
	ft_printf("(unsigned ft_printf): %u\n", u_m);
	printf("\nNow maximum and minimum values\n");
	int d_min = INT_MIN;
	int d_max = INT_MAX;
	unsigned int u_max = UINT_MAX;
	printf("(min printf): %d\n", d_min);
	ft_printf("(min ft_printf): %d\n", d_min);
	printf("(max printf): %d\n", d_max);
	ft_printf("(max ft_printf): %d\n", d_max);
	printf("(max unsigned printf): %u\n", u_max);
	ft_printf("(max unsigned ft_printf): %u\n", u_max);
	printf("\n\nT E S T I N G  I N T E G E R S with %%i \n\n");
    printf("(negative printf): %i\n", d_n);
    ft_printf("(negative ft_printf): %i\n", d_n);
    printf("(positive printf): %i\n", d_p);
    ft_printf("(positive ft_printf): %i\n", d_p);
	printf("\nNow maximum and minimum values\n");
	printf("(min printf): %i\n", d_min);
   	ft_printf("(min ft_printf): %i\n", d_min);
   	printf("(max printf): %i\n", d_max);
   	ft_printf("(max ft_printf): %i\n", d_max);
// Pointers
	printf("\n\nT E S T I N G   P O I N T E R S\n\n");
	void *p_null = NULL;
	printf("%p (null): %p\n", "Example pointer label", p_null);
	ft_printf("%p (null): %p\n", "Example pointer label", p_null);
// Hexadecimal
	printf("\n\nT E S T I N G   H E X A D E C I M A L S\n\n");
	int x_n = -123;
	int x_p = 12345;
	unsigned int X_m = 65535;
	printf("(negative): %x\n", x_n);
	ft_printf("(negative): %x\n", x_n);
	printf("(positive): %x\n", x_p);
	ft_printf("(positive): %x\n", x_p);
	printf("(caps): %X\n", X_m);
	ft_printf("(caps): %X\n", X_m);
	printf("\nNow maximum and minimum values\n");
	int8_t min_int8 = INT8_MIN;
	int16_t min_int16 = INT16_MIN;
	int32_t min_int32 = INT32_MIN;
	uint8_t max_uint8 = UINT8_MAX;
	uint16_t max_uint16 = UINT16_MAX;
	uint32_t max_uint32 = UINT32_MAX;
	printf("%x (min int8): %x\n", min_int8, min_int8);
	ft_printf("%x (min int8): %x\n", min_int8, min_int8);
	printf("%x (min int16): %x\n", min_int16, min_int16);
	ft_printf("%x (min int16): %x\n", min_int16, min_int16);
	printf("%x (min int32): %x\n", min_int32, min_int32);
	ft_printf("%x (min int32): %x\n", min_int32, min_int32);
// Imprimir y comparar valores máximos
	printf("%x (max uint8): %x\n", max_uint8, max_uint8);
	ft_printf("%x (max uint8): %x\n", max_uint8, max_uint8);
	printf("%x (max uint16): %x\n", max_uint16, max_uint16);
	ft_printf("%x (max uint16): %x\n", max_uint16, max_uint16);
	printf("%x (max uint32): %x\n", max_uint32, max_uint32);
	ft_printf("%x (max uint32): %x\n", max_uint32, max_uint32);
// Percentage
	printf("\n\nT E S T I N G   P R I N T I N G %%\n\n");
	printf("using printf: %%\n");
	ft_printf("using ft_printf: %%\n");
	return (0);
}
*/
