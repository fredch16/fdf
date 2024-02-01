/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:16:41 by fcharbon          #+#    #+#             */
/*   Updated: 2023/12/07 17:33:11 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printnbr_base(long n, int base, char *symbols)
{
	int		count;

	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_printnbr_base(-n, base, symbols) + 1);
	}
	else if (n < base)
		return (ft_printchar(symbols[n]));
	else
	{
		count = ft_printnbr_base(n / base, base, symbols);
		return (count + ft_printnbr_base(n % base, base, symbols));
	}
}

/*int	main()
{
	ft_printnbr_base(122, 2, "01");
	return (0);
}*/
