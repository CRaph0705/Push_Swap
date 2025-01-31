/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:16:31 by rcochran          #+#    #+#             */
/*   Updated: 2025/01/24 17:37:12 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*get_number_in_new_base(int nbr, char *base);
int		is_base_valid(char *base);
int		ft_atoi_base(char *str, char *base);
int		is_in_base(char c, char *base);

char	*get_number_in_new_base(int nbr, char *base)
{
	unsigned int	n;
	unsigned int	base_len;
	int				base_is_valid;
	int				i;
	char			*str;

	str = NULL;
	i = 0;
	base_is_valid = is_base_valid(base);
	base_len = ft_strlen(base);
	if (base_is_valid != 1)
		return (NULL);
	if (nbr < 0)
	{
		i++;
		n = -nbr;
		str[0] = '-';
	}
	else
		n = nbr;
	while (n >= base_len)
	{
		str[i] = base[n % base_len] - '0';
		n = n / base_len;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	num;
	char	*num_str;

	if (is_base_valid(base_from) == 0 || is_base_valid(base_to) == 0)
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	num_str = get_number_in_new_base(num, base_to);
	return (num_str);
}

/* int	main (int ac, char **av)
{
	if (ac < 3)
		return;
	printf("nbr : %s\n base_from : %s\n base_to : %s\n new_num : %s", av[1], av[2], av[3], ft_convert_base(av[1], av[2], av[3]));
	return (0);
} */
