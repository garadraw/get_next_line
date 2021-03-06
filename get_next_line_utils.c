/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsimeono <vsimeono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:11:58 by vsimeono          #+#    #+#             */
/*   Updated: 2021/11/13 14:06:16 by vsimeono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < (int)n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len-- > 0)
		{
			*(d + len) = *(s + len);
		}
	}
	else
	{
		while (len-- > 0)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	return (d);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, lens1);
	ft_memcpy(str + lens1, s2, lens2);
	*(str + lens1 + lens2) = '\0';
	free((void *)s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	lenstr;

	i = 0;
	if (!s)
		return (NULL);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	lenstr = ft_strlen(s);
	if (start >= lenstr)
		return (p);
	while (i < len)
	{
		*(p + i) = *(s + start);
		i++;
		start++;
	}
	*(p + i) = '\0';
	return (p);
}
