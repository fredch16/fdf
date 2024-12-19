/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:54:11 by fcharbon          #+#    #+#             */
/*   Updated: 2024/01/12 17:14:01 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	total_len(const char *s, char c)
{
	size_t	result;

	result = 0;
	while (*s)
	{
		if (*s != c)
		{
			result++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		index;
	size_t		len;

	if (!s)
		return (NULL);
	index = 0;
	result = malloc(sizeof(char *) * (total_len(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			result[index++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	result[index] = 0;
	return (result);
}
