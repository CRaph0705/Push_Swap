/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:03:44 by raphaelcoch       #+#    #+#             */
/*   Updated: 2025/02/07 11:24:24 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char			**parse(char **str_array);
static size_t	get_array_len(char **array);

static size_t	get_array_len(char **array)
{
	size_t	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

char	**parse(char **str_array)
{
	char	**formated_array;
	int		i;
	size_t	nb_elem;

	i = 0;
	formated_array = NULL;
	formated_array = ft_calloc(1, 1);
	if (!formated_array)
		return (NULL);
	while (str_array[i])
	{
		nb_elem = get_array_len(formated_array);
		formated_array[nb_elem] = ft_split(str_array[i], ' ');
		i++;
	}
	return (formated_array);
}
//TODO
/* checker quand on a un char '\0' au milieu d'une string parmi les arg */

