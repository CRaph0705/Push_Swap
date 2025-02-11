/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:12:24 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/11 15:56:33 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*cascade_atoi(char **formated_array, int *dest);
int	atoi_dest(char	*num_ptr, int *dest);
int	*format_arg(char **num_str_array);

//free formated_array l.74 or in error handler

int	*cascade_atoi(char **formated_array, int *dest)
{
	int	i;

	i = 0;
	while (*formated_array)
	{
		dest[i] = atoi_dest(*formated_array, dest);
		formated_array++;
		i++;
	}
	return (dest);
}

int	atoi_dest( char	*num_ptr, int *dest)
{
	int		sign;
	long	nbr;

	sign = 1;
	nbr = 0;
	if (!num_ptr)
		return (0);
	if (*num_ptr == '-' && *num_ptr++)
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
	*dest = nbr;
	return (1);
}

int	*format_arg( char **num_str_array)
{
	int				*int_array;
	char		**formated_array;

	formated_array = parse(num_str_array, ' ');
	int_array = ft_calloc(get_array_len(formated_array), sizeof(int *));
	if (!int_array)
		return (NULL);
	int_array = cascade_atoi(formated_array, int_array);
	return (int_array);
}
