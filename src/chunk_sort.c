/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:23:55 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/27 14:28:32 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	fill_chunk(stack_a, stack_b);
	pushback_chunks(stack_a, stack_b);
	
/* 	ft_putstr("stack a\n");
	display_stack(stack_a, 1);
	ft_putstr("stack b\n");
	display_stack(stack_b, 1); */
} 

// mediane ou point pivot
// chunk 1 -> target pos entre 0 et index max / 4
// chunk 2 -> target pos entre index max / 4 et index max / 2
// chunk 3 -> target pos entre index max / 2 et 3 index max / 4
// chunk 4 -> target pos entre 3 index max / 4 et index max

// int i : index de chunk
// fixer une condition d'entrée dans le chunk en fonction de la target pos
// genre if (*stack -> target_pos) < index_max / index chunk

// limit_chunk1 == ptr sur node dont target_pos == 0
// limit_chunk2 == ptr sur node dont target_pos == max_target_pos * 1/3
// limit_chunk3 == ptr sur node dont target_pos == max_target_pos * 2/3

/*//TODO >>>>>>>>>> fill chunk functions <<<<<<<<<< */
// while stack a != NULL 
//get_next_chunk(stack, chunk_limit);
// -> while (*stack)->target_pos < chunk_limit->target_pos
//get_next_chunk_node
