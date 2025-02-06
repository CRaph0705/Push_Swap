/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:05:44 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/06 18:08:01 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//get stacks
// init stack a, b
// stack a = foreach (formated_array_item as item) -> new list item

t_list	*init_stack()
{
	t_list	stack_a;
	t_list	stack_b;
	stack_a = ft_lstnew(NULL);
	return(stack_a, stack_b);
}
