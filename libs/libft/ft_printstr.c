/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:50:53 by fcharbon          #+#    #+#             */
/*   Updated: 2023/12/07 17:54:07 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (s && *s)
	{
		ft_printchar(*s++);
		i++;
	}
	return (i);
}
