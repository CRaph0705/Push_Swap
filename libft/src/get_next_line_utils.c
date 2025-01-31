/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:35:31 by rcochran          #+#    #+#             */
/*   Updated: 2025/01/21 13:53:59 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elem, size_t size)
{
	char	*array;
	size_t	i;

	i = 0;
	array = malloc(size * n_elem);
	if (!array)
		return (NULL);
	while (i < size * n_elem)
	{
		array[i] = '\0';
		i++;
	}
	return (array);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}
/* 
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		str_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = NULL;
	str_len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = malloc((size_t)(str_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
} */

/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	sub = NULL;
	if (!s || len == 0)
		return (ft_calloc(1, 1));
	i = ft_strlen((char *)s);
	if (start > i)
		return (ft_calloc(1, 1));
	if (i - start < (unsigned int)len)
		sub = ft_calloc((size_t)((i - start) + 1), sizeof(char));
	else
		sub = ft_calloc((len + 1), sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] && i < (unsigned int)len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
} */
/* 
char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	if (s)
	{
		while (*s && *s != (c % 256))
		{
			s++;
		}
		if (*s == (c % 256))
			return ((char *)s);
	}
	return (NULL);
}
 */