/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:24:30 by fcharbon          #+#    #+#             */
/*   Updated: 2023/11/20 16:32:00 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*fs1;
	unsigned char	*fs2;

	fs1 = (unsigned char *)s1;
	fs2 = (unsigned char *)s2;
	while (n > 0 && *fs1 != '\0' && *fs1 == *fs2)
	{
		fs1++;
		fs2++;
		n--;
	}
	if (n == 0 || (*fs1 == '\0' && *fs2 == '\0'))
		return (0);
	else
	{
		return (*fs1 - *fs2);
	}
}
