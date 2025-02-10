/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:42:01 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/07 17:17:35 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

/* init.c */
t_list			**init_stacks(void);
t_list			**init_program(int ac, char **av);

/* parse.c */
char			**parse(char **str_array);
static size_t	get_array_len(char **array);

/* error handling */
int				check_arg_valid(int ac, char **av);
/* core */
char			**push_swap(int *stack_a);

#endif
