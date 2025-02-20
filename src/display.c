/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:13:30 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/20 13:29:32 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_node(t_stack *node, int fd);
void	display_stack(t_stack **stack, int fd);

/* Display value, index, target_pos of *node */
void	display_node(t_stack *node, int fd)
{
	if (!node)
		return ;
	ft_printf("|[ value : %i ]", node->value);
	ft_printf("[index : %i ]", node->index);
	ft_printf("[target_pos : %i ]|\n", node->target_pos);
	(void)fd;
}

void	display_stack(t_stack **stack, int fd)
{
	t_stack	*node;

	if (!stack || !*stack)
	{
		ft_printf(">>>display_stack : !stack || !*stack\n");
		return ;
	}
	node = *stack;
	while (node != NULL)
	{
		display_node(node, fd);
		node = node->next;
	}
}
