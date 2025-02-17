/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:12:24 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/17 11:58:42 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*cascade_atoi(char **formated_array, size_t len);
int	atoi_strict(char	*num_ptr);
int	*format_arg(char **num_str_array);
int	check_if_convertible(char **str_array);
int	is_num(char *str);
int	ft_is_atoiable(char	*num_ptr);
int ft_all_atoiable(char **array);

//free formated_array l.74 or in error handler

int	*cascade_atoi(char **valid_array, size_t len)
{
	size_t	i;
	int	*int_array;
	if (len == 0)
		return (ft_printf("cascade atoi, len == 0\n"), NULL);
	int is_atoiable = ft_all_atoiable(valid_array);
	if (is_atoiable == 0)
		return (NULL);
	int_array = malloc((len + 1) * sizeof(int));
	if(!int_array)
		return (ft_printf("cascade atoi, no malloc\n"),NULL);
	i = 0;


	while (i < len)
	{
		int_array[i] = atoi_strict(valid_array[i]);
		i++;
	}
	i = 0;
	if (!int_array)
		return (ft_printf("cascade atoi >>> no int_array"), NULL);

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
int ft_all_atoiable(char **array)
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
	return (1);
}
//si retval == null fonction precedente doit free num str array
int	*format_arg( char **av)
{
	int			*formated_array;
	char		**parsed_arg;
	size_t		len;
	parsed_arg = parse(av, ' ');
	if (!parsed_arg)
		return (NULL);
	if (check_if_convertible(parsed_arg) == 0)
		return (free(parsed_arg), ft_printf("format_arg is_convertible KO\n"), NULL);

	len = get_array_len(parsed_arg);
	formated_array = ft_calloc(len + 1, sizeof(int));
	if (!formated_array)
		return (NULL);
	formated_array = cascade_atoi(parsed_arg, len);
	if (formated_array == NULL)
		return (0);
	return (ft_printf("format_arg is_convertible OK\n"), formated_array);
}

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

	i = 0;
	if (str[i + 1] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}