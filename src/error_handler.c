/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:05:46 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/07 17:21:13 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* If no parameters are specified, the program must not display anything and give the
prompt back. */

/* • In case of error, it must display "Error" followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer and/or there are duplicates. */

int	check_arg_valid(int ac, char **av);

int	check_arg_valid(int ac, char **av)
{
	if (ac < 2)
		return (0);
	return (1);
}

void	display_error(void)
{
	ft_putstr_fd("Error\n", 2);
}
/* error handler isdigit sur chaque item parsé, à la moindre erreur break */