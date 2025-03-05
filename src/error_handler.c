/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:05:46 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/05 23:33:51 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_dupes(int *tab, size_t len);
int		check_arg_valid(int ac, char **av);

int	check_arg_valid(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
		return (0);
	while (av[i])
	{
		if (ft_strlen(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/* Display Error */
void	error_handler(void)
{
	ft_putstr_fd("Error\n", 2);
}

/* returns 1 if it has dupes */
int	check_dupes(int *tab, size_t len)
{
	size_t	i;
	size_t	j;

	if (len == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (i + j < len)
		{
			if (tab[i] == tab[i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
