/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:03:44 by raphaelcoch       #+#    #+#             */
/*   Updated: 2025/04/04 10:31:23 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t				get_array_len(char **array);
char				**merge_array(char **array, char **append);
char				**parse(char **str_array, char c);
void				*cascade_free(char **array);
// static void			*reverse_cascade_free(char **str, int i);

char	**parse(char **str_array, char c)
{
	char	**parsed_array;
	int		i;
	char	**split;

	i = 0;
	parsed_array = NULL;
	while (str_array[i])
	{
		split = ft_split(str_array[i], c);
		if (!split)
			return (cascade_free(parsed_array), NULL);
		parsed_array = merge_array(parsed_array, split);
		i++;
	}
	return (parsed_array);
}

/* static void	*reverse_cascade_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
} */

void	*cascade_free(char **array)
{
	int	i;

	if (array == NULL)
		return (NULL);
	i = 0;
	while (array[i] != 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

size_t	get_array_len( char **array)
{
	size_t	len;

	len = 0;
	while (array && array[len] != NULL)
		len++;
	return (len);
}

char	**merge_array(char **array, char **append)
{
	char		**fusion;
	size_t		len_fusion;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	len_fusion = get_array_len((char **)array)
		+ get_array_len((char **)append) + 1;
	fusion = ft_calloc(len_fusion, sizeof(char *));
	if (!fusion)
		return (NULL);
	while (array && array[i])
	{
		fusion[i] = ft_strdup(array[i]);
		i++;
	}
	while (append[j])
	{
		fusion[i] = ft_strdup(append[j]);
		i++;
		j++;
	}
	return (cascade_free(append), cascade_free(array), fusion);
}
