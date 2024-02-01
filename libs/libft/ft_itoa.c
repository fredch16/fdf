/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:23:08 by fcharbon          #+#    #+#             */
/*   Updated: 2023/11/20 20:19:17 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_num_digits(int n)
{
	int	num_digits;

	num_digits = 1;
	while (n >= 10)
	{
		n /= 10;
		num_digits++;
	}
	return (num_digits);
}

void	int_to_ascii(int num_digits, int sign, int n, char *result)
{
	int		temp;

	temp = num_digits -(sign == 1);
	while (temp >= 0)
	{
		result[temp] = '0' + (n % 10);
		n /= 10;
		temp--;
	}
	if (sign == -1)
		result[0] = '-';
	result[num_digits + (sign == -1)] = '\0';
}

char	*ft_itoa_intmin(void)
{
	char	*result;
	int		temp;
	int		n;

	temp = 9;
	n = 214748364;
	result = (char *)malloc(sizeof(char) * 12);
	if (result == NULL)
		return (NULL);
	while (temp >= 0)
	{
		result[temp] = '0' + (n % 10);
		n /= 10;
		temp--;
	}
	result[0] = '-';
	result[10] = '8';
	result[11] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		num_digits;
	char	*result;

	sign = 1;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			result = ft_itoa_intmin();
			return (result);
		}
		sign = -1;
		n = -n;
	}
	num_digits = find_num_digits(n);
	result = (char *)malloc(num_digits + (sign == -1) + 1);
	if (result == NULL)
		return (NULL);
	int_to_ascii(num_digits, sign, n, result);
	return (result);
}
