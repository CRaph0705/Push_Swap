/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:27:10 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/14 16:49:52 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int *value);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack, void (*del)(void *));
void	ft_stackdelone(t_stack *stack, void (*del)(void *));

/* create new element */
t_stack	*ft_stacknew(int *value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

/* add new element at end of list */
void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = ft_stacklast(*stack);
	if (last)
	{
		last->next = new;
	}
	else
		*stack = new;
}

/* add new element at beginnig of list */
void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

/* delete target list */
void	ft_stackclear(t_stack **stack, void (*del)(void *))
{
	t_stack	*current;
	t_stack	*tmp_next;

	if (!stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		tmp_next = current->next;
		ft_stackdelone(current, del);
		current = tmp_next;
	}
	*stack = NULL;
}

/* delete target element */
void	ft_stackdelone(t_stack *node, void (*del)(void *))
{
	if (node)
	{
		del(node->value);
		free(node);
	}
}
