/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:03:44 by raphaelcoch       #+#    #+#             */
/*   Updated: 2025/02/11 18:46:32 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t				get_array_len(char **array);
char				**merge_array(char **array, char **append);
char				**parse(char **str_array, char c);
static void			*cascade_free(char **array);

char	**parse(char **str_array, char c)
{
	char	**parsed_array;
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	parsed_array = ft_calloc(1, sizeof(char *));
	// ft_printf("debug\n");
	// ft_printf("str_array[0] : %s\n", str_array[0]);
	while (str_array[i])
	{
		ft_printf("str_array[i] : %s\n", str_array[i]);
		split = ft_split(str_array[i], c);
		if (!split)
			return (cascade_free(parsed_array), NULL);
		ft_printf("debug\n");
		while (split[j])
		{
			ft_printf("split[i] : %s\n", split[j]);
			j++;
		}
		//ici le premier split est bon puis seg fault
		parsed_array = merge_array(parsed_array, split);
		// i = 0;
		i++;
		j = 0;
	}
	while (parsed_array[j])
	{
		ft_printf("parsed_array[j] : %s\n", parsed_array[j]);
		j++;
	}
	ft_printf("debug\n");
	return (parsed_array);
}

static void	*cascade_free(char **array)
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
	while (array[len] != NULL)
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
	len_fusion = get_array_len((char **)array) + get_array_len((char **)append) + 1;
	fusion = ft_calloc(len_fusion, sizeof(char *));
	if (!fusion)
		return (NULL);
	while (array[i])
	{
		fusion[i] = array[i];
		i++;
	}
	while (append[j])
	{
		fusion[i] = append[j];
		i++;
		j++;
	}
	return (fusion);
}
