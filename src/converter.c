/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:12:24 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/12 14:26:35 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*cascade_atoi(char **formated_array, size_t len);
int	atoi_strict(char	*num_ptr);
int	*format_arg(char **num_str_array);

//free formated_array l.74 or in error handler

int	*cascade_atoi(char **valid_array, size_t len)
{
	size_t	i;
	int		*int_array;
	int		is_atoiable;

	if (len == 0)
		return (NULL);
	is_atoiable = ft_all_atoiable(valid_array);
	if (is_atoiable == 0)
		return (NULL);
	int_array = malloc((len + 1) * sizeof(int));
	if (!int_array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		int_array[i] = atoi_strict(valid_array[i]);
		i++;
	}
	i = 0;
	if (!int_array)
		return (NULL);
	return (int_array);
}

int	atoi_strict(char	*num_ptr)
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
	return ((int)nbr);
}

//si retval == null fonction precedente doit free num str array
int	*format_arg( char **parsed_arg)
{
	int			*formated_array;
	size_t		len;

	if (!parsed_arg)
		return (NULL);
	if (check_if_convertible(parsed_arg) == 0)
		return (cascade_free(parsed_arg), NULL);
	len = get_array_len(parsed_arg);
	formated_array = cascade_atoi(parsed_arg, len);
	if (formated_array == NULL)
	{
		cascade_free(parsed_arg);
		return (0);
	}
	cascade_free(parsed_arg);
	return (formated_array);
}
