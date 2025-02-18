/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:42:01 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/18 12:13:36 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
/* typedef struct s_ps
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_ps; */

/* {
	(int)	value,
	(s_stack)	*next
}
 */
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;
// int			id;
// int *nbr = (int *)ft_malloc(stack_a 5, sizeof(int));

/* init.c */
t_stack			**init_program(int ac, char **av);

/* parse.c */
char			**parse(char **str_array, char c);
size_t			get_array_len(char **array);

/* converter.c */
int				*cascade_atoi(char **formated_array, size_t len);
int				atoi_strict(char	*num_ptr);
int				*format_arg(char **num_str_array);
int				check_if_convertible(char **str_array);

/* error handling */
int				check_arg_valid(int ac, char **av);
void			freetout(void);
void			error_handler(void);
int				check_stack_errors(t_stack ***stacks);
int				check_dupes(int *tab, size_t len);

/* stack utils */
t_stack			*ft_stacknew(int value);
void			ft_stackadd_back(t_stack **stack, t_stack *new);
void			ft_stackadd_front(t_stack **stack, t_stack *new);
void			ft_stackclear(t_stack **stack);
void			ft_stackdelone(t_stack *node);
int				ft_stacksize(t_stack *stack);
t_stack			*ft_stacklast(t_stack *stack);

/* core */
void			push_swap(t_stack **stack_a, t_stack **stack_b);

/* displays node value in specified fd */
void			display_stack(t_stack *stack, int fd);

/* INSTRUCTIONS */

/* SWAP */
/* Swap the first 2 elements at the top of given stack. */
void			ft_swap(t_stack **stack);
/* sa (swap a): Swap the first 2 elements at the top of stack a. 
Do nothing if there is only one or no elements. */
void			sa(t_stack **stack_a);
/* sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements. */
void			sb(t_stack **stack_b);
/* ss : sa and sb at the same time. */
void			ss(t_stack **stack_a, t_stack **stack_b);
#endif
