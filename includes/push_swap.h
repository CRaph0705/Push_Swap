/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:42:01 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/19 15:53:17 by rcochran         ###   ########.fr       */
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
	int				value;
	struct s_stack	*next;
	int				target_pos;
	int				index;
}
 */
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	long			target_pos;
	long			index;
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
void			ft_stackadd_back(t_stack **stack, t_stack *node);
void			ft_stackadd_front(t_stack **stack, t_stack *node);
void			ft_stackclear(t_stack **stack);
void			ft_stackdelone(t_stack *node);
int				ft_stacksize(t_stack *stack);
t_stack			*ft_stacklast(t_stack **stack);

/* stack init */

void			update_indices(t_stack **stack);
void			fill_target_pos(t_stack **stack);
void			set_target_pos(t_stack *stack_a, long pos);
/* core */
void			push_swap(t_stack **stack_a, t_stack **stack_b);

/* DISPLAY */

/* displays node value in specified fd */
void			display_stack(t_stack **stack, int fd);

/* INSTRUCTIONS */
/* SWAP */

void			swap(t_stack **stack);
void			sa(t_stack **stack_a);
void			sb(t_stack **stack_b);
void			ss(t_stack **stack_a, t_stack **stack_b);

/* PUSH */

void			push(t_stack **src, t_stack **dest);
void			pa(t_stack **stack_b, t_stack **stack_a);
void			pb(t_stack **stack_a, t_stack **stack_b);

/* ROTATE */

void			r(t_stack **stack);
void			ra(t_stack **stack_a);
void			rb(t_stack **stack_b);
void			rr(t_stack **stack_a, t_stack **stack_b);

/* REVERSE ROTATE */

void			r_r(t_stack	**stack);
void			rra(t_stack **stack_a);
void			rrb(t_stack **stack_b);
void			rrr(t_stack **stack_a, t_stack **stack_b);

#endif
