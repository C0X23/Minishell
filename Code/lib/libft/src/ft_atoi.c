/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <francis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:15:23 by fallan            #+#    #+#             */
/*   Updated: 2024/12/27 16:55:06 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	remove_whitespaces(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi_adapted(const char *str)
{
	long	nb;
	int		i;
	int		sign;

	nb = 0;
	i = 0;
	i = remove_whitespaces(str, i);
	sign = 1;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if ((sign == 1 && nb > INT_MAX) || (sign == -1 && (-nb) < INT_MIN))
			return (-1);
		i++;
	}
	return (sign * nb);
}

/* #include <unistd.h>
#include <stdlib.h>
int	test(int number, char *str)
{
	int result1 = ft_atoi(str);
	int result2 = atoi(str);

	if (result1 == result2)
		printf("test %d OK: same return '%d'\n", number, result2);
	else
		printf("test %d KO: atoi returns '%d', \
		ft_atoi returns '%d'\n", number, result2, result1);
	return (0);
}

int	main(void)
{
	// test(1, "123456");
	// test(2, "-123456");
	// test(3, "123456abcde");
	// test(4, "abcde123456");
	// test(5, "123456abcde123456");
	test(6, "  +000456abcde----");
	test(7, "  -000456393939393939393939393abc55554de     ");
	test(8, "  -000456abc55554de     ");
	return (0);
}
 */