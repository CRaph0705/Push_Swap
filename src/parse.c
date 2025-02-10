/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:03:44 by raphaelcoch       #+#    #+#             */
/*   Updated: 2025/02/10 19:05:12 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char			**parse(char **str_array);
size_t				get_array_len(const char **array);

size_t	get_array_len(const char **array)
{
	size_t	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

const char	**parse(char **str_array)
{
	char	**formated_array;
	int		i;
	size_t	nb_elem;

	i = 0;
	nb_elem = 0;
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

