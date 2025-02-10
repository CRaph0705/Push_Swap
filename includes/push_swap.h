/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:42:01 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/10 18:33:33 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

/* init.c */
t_list			**init_stacks(void);
t_list			**init_program(int ac, char **av);

/* parse.c */
const char		**parse(char **str_array);
size_t			get_array_len(const char **array);

/* converter.c */
int				*cascade_atoi(const char **formated_array, int *dest);
int				atoi_dest(const char	*num_ptr, int *dest);
int				*format_arg(char **av);

/* error handling */
int				check_arg_valid(int ac, char **av);
void			freetout(void);
void			error_handler(void);
int				check_stack_errors(t_list **stacks);

/* core */
char			**push_swap(int *stack_a);

#endif
