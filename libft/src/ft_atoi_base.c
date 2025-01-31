/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:41:56 by rcochran          #+#    #+#             */
/*   Updated: 2025/01/24 17:14:00 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	is_in_base(char c, char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		num;
	size_t	base_len;

	base_len = ft_strlen(base);
	if (is_base_valid(base) != 1)
		return (0);
	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && is_in_base(str[i], base) == 1)
	{
		num = num * (int)base_len + str[i] - '0';
		i++;
	}
	return (num * sign);
}

int	is_in_base(char c, char *base)
{
	size_t	i;
	size_t	base_len;

	base_len = (int)ft_strlen(base);
	i = 0;
	while ((i < base_len) && (c != base[i]))
	{
		i++;
	}
	if (base[i] == c)
		return (1);
	return (0);
}