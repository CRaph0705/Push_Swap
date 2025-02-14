/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:13:30 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/14 17:07:20 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_node(t_stack *node, int fd);
void	display_stack(t_stack *stack, int fd);

void	display_node(t_stack *node, int fd)
{
	if (!node)
		return ;
	ft_putnbr_fd(node->value, fd);
}

void	display_stack(t_stack *stack, int fd)
{
	if (!stack)
		return ;
	while (stack != NULL)
	{
		display_node(stack, fd);
		stack = stack->next;
	}
}
