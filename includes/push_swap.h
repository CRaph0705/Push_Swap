/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:42:01 by rcochran          #+#    #+#             */
/*   Updated: 2025/02/14 17:27:48 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

/* {
	(int)	value,
	(s_stack)	*next
}
 */
typedef struct s_stack
{
	int				value;
	// int			id;
	// int *nbr = (int *)ft_malloc(stack_a 5, sizeof(int));
	struct s_stack	*next;
}					t_stack;

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
t_stack			*ft_stacknew(int *value);
void			ft_stackadd_back(t_stack **stack, t_stack *new);
void			ft_stackadd_front(t_stack **stack, t_stack *new);
void			ft_stackclear(t_stack **stack, void (*del)(void *));
void			ft_stackdelone(t_stack *stack, void (*del)(void *));
int				ft_stacksize(t_stack *stack);
t_stack			*ft_stacklast(t_stack *stack);

/* core */
char			**push_swap(int *stack_a);

/* displays node value in specified fd */
void			display_stack(t_stack *stack, int fd);

#endif
