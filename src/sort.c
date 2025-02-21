/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:16:22 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/21 11:07:16 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int		is_sorted(t_stack **stack);

/* ASC SORTED */
/* DESC SORTED */

// int	is_sorted(t_stack **stack)
// {
// 	if ( /* sorting logic here */)
// 		return (1);
// 	return (0);
// }

/*
tant que stack a est non vide :
	récupérer la min value de la current stack a.
	rotate jusqu'à avoir min value de a en haut de la stack a
	push min value de a dans b

tant que stack b est non vide :
	push b dans a

instant parano : ultime verif de target position == index pour chaque node
*/
