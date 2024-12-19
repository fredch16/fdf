/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:12:27 by fcharbon          #+#    #+#             */
/*   Updated: 2023/11/17 17:25:50 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*originaldest;

	originaldest = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (originaldest);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dup_str;

	if (src == 0)
		return (0);
	len = ft_strlen(src);
	dup_str = (char *)malloc(len + 1);
	if (dup_str == 0)
		return (0);
	ft_strcpy(dup_str, src);
	return (dup_str);
}
