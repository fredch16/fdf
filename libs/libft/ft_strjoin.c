/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:30:37 by fcharbon          #+#    #+#             */
/*   Updated: 2023/11/20 22:27:53 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*cat_string;

	cat_string = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (cat_string);
}

int	total_array_len(char const *s1, char const *s2)
{
	return (ft_strlen(s1) + ft_strlen(s2) + 1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*joint;

	if (*s1 == '\0' && *s2 == '\0')
		return (ft_strdup(""));
	len = total_array_len(s1, s2);
	joint = malloc(sizeof(char) * len);
	ft_memset(joint, '\0', len);
	ft_strcat(joint, (char *)s1);
	ft_strcat(joint, (char *)s2);
	return (joint);
}

/*int main() {
  char s1[] = "Hello";
  char s2[] = "Noway";
  printf("result: %s", ft_strjoin(s1, s2));
  return 0;
}*/
