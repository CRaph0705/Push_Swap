/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:13:33 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/03 16:38:38 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

/* apply given instruction to the specified stack(s) */
void	do_instruction(char *instruction, t_stack **stack_a, t_stack **stack_b);

/* display OK or KO if stack a is sorted correctly or not */
void	check(t_stack **stack_a, t_stack **stack_b);

#endif