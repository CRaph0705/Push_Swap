/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:05:46 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/14 16:54:00 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* If no parameters are specified, the program must not display anything and give the
prompt back. */

/* • In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates. */

/* Returns 1 if it has dupes */
int check_dupes(int *tab, size_t len);
int	check_arg_valid(int ac, char **av);

int	check_arg_valid(int ac, char **av)
{
	if (ac < 2)
		return (0);
	(void)av;
	return (1);
}

void	freetout(void)
{
	ft_putstr_fd("Freetout\n", 1);
}

void	error_handler(void)
{
	ft_putstr_fd("error_handler\n", 1);
}

void	display_error(void)
{
	ft_putstr_fd("Error\n", 2);
}
/* error handler isdigit sur chaque item parsé, à la moindre erreur break */

int	check_stack_errors(t_stack ***stacks)
{
	(void)stacks;
	return (0);
}

/* returns 1 if it has dupes */
int check_dupes(int *tab, size_t len)
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