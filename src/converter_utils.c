/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:05:23 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/11 20:21:30 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_if_convertible(char **str_array);
int			is_num(char *str);
int			ft_is_atoiable(char	*num_ptr);
int			ft_all_atoiable(char **array);

int	check_if_convertible(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i])
	{
		if (is_num(str_array[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_num(char *str)
{
	int	i;
	int	is_digit;

	i = 0;
	is_digit = 0;
	if (str)
	{
		if (str[i] && (str[i] == '-' || str[i] == '+'))
			i++;
		while (str[i] != '\0')
		{
			if (ft_isdigit(str[i]) == 0)
				return (0);
			is_digit = 1;
			i++;
		}
	}
	return (is_digit);
}

int	ft_all_atoiable(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_is_atoiable(array[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_is_atoiable(char	*num_ptr)
{
	int		sign;
	long	nbr;

	sign = 1;
	nbr = 0;
	if (!num_ptr)
		return (0);
	if (*num_ptr == '-' && *(++num_ptr))
		sign = -1;
	while (*num_ptr)
	{
		if (!ft_isdigit(*num_ptr))
			return (0);
		nbr = nbr * 10 + (*num_ptr - '0');
		num_ptr++;
	}
	nbr *= sign;
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	return (1);
}
