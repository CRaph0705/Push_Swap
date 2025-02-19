/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:27:10 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/19 12:19:20 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int value);
void	ft_stackadd_back(t_stack **stack, t_stack *node);
void	ft_stackadd_front(t_stack **stack, t_stack *node);
void	ft_stackclear(t_stack **stack);
void	ft_stackdelone(t_stack *node);

/* create new element */
t_stack	*ft_stacknew(int value)
{
	t_stack	*new_node;

	ft_printf(">>>ft_stacknew\n");
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->target_pos = -1;
	new_node->index = -1;
	return (new_node);
}

/* add new element at end of stack */
void	ft_stackadd_back(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	ft_printf(">>>ft_stackadd_back\n");
	if (!node)
		return ;
	last = ft_stacklast((stack));
	if (last != NULL)
	{
		ft_printf(">>>ft_stackadd_back : if !last\n");
		last->next = node;
	}
	else
	{
		ft_printf(">>>ft_stackadd_back : else\n");
		*stack = node;
	}
}

/* add new element at beginnig of stack */
void	ft_stackadd_front(t_stack **stack, t_stack *node)
{
	t_stack	*head;

	ft_printf(">>>ft_stackadd_front\n");
	if (!node)
	{
		ft_printf("no node, return\n");
		return ;
	}
	ft_printf("node, continue\n");
	head = (*stack);
	if (!head)
	{
		ft_printf("no head, assign\n");
		node->next = NULL;
		*stack = node;
		return ;
	}
	ft_printf("head, continue\n");
	*stack = node;
	node->next = head;
}

/* delete target list */
void	ft_stackclear(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		ft_stackdelone(tmp);
	}
	*stack = NULL;
}

/* delete target element */
void	ft_stackdelone(t_stack *node)
{
	if (node)
	{
		free(node);
	}
}
