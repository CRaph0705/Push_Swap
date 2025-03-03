/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:41:02 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/03 17:03:57 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_instruction(char *instruction, t_stack **stack_a, t_stack **stack_b);
void	check(t_stack **stack_a, t_stack **stack_b);

// takes stack
// read prompt
// check stack
// assert error if stack not valid
// gnl list command
// parse
// foreach exec
// check if is sorted
// retval

void	do_instruction(char *instruction, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(instruction, "sa\n", 3))
		sa(stack_a, 0);
	else if (!ft_strncmp(instruction, "sb\n", 3))
		sb(stack_a, 0);
	else if (!ft_strncmp(instruction, "ss\n", 3))
		ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(instruction, "pb\n", 3))
		pb(stack_a, stack_b, 0);
	else if (!ft_strncmp(instruction, "pa\n", 3))
		pa(stack_b, stack_a, 0);
	else if (!ft_strncmp(instruction, "ra\n", 3))
		ra(stack_a, 0);
	else if (!ft_strncmp(instruction, "rb\n", 3))
		rb(stack_b, 0);
	else if (!ft_strncmp(instruction, "rr\n", 3))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(instruction, "rra\n", 4))
		rra(stack_a, 0);
	else if (!ft_strncmp(instruction, "rrb\n", 4))
		rrb(stack_b, 0);
	else if (!ft_strncmp(instruction, "rrr\n", 4))
		rrr(stack_a, stack_b, 0);
	else
		free(instruction);
}

void	check(t_stack **stack_a, t_stack **stack_b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		do_instruction(instruction, stack_a, stack_b);
		free(instruction);
		instruction = get_next_line(0);
	}
	free(instruction);
	if (is_sorted(stack_a) && (*stack_b) == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return (error_handler(), 0);
	stack_a = init_program(ac, av);
	if (!stack_a)
		return (0);
	check(&stack_a, &stack_b);
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
	return (0);
}
