/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:27:10 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/18 20:04:45 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int value);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
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
void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	ft_printf(">>>ft_stackadd_back\n");
	if (!new)
		return ;
	last = ft_stacklast((stack));
	if (last != NULL)
	{
		ft_printf(">>>ft_stackadd_back : if !last\n");
		last->next = new;
	}
	else
	{
		ft_printf(">>>ft_stackadd_back : else\n");
		*stack = new;
	}
}

/* add new element at beginnig of stack */
void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	ft_printf(">>>ft_stackadd_front\n");
	if (*stack == NULL)
		*stack = new;
	new->next = *stack;
	*stack = new;
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
