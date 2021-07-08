/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:42:51 by jimikim           #+#    #+#             */
/*   Updated: 2021/07/04 00:00:21 by jimikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack	t_stack;
typedef struct s_node	t_node;
typedef struct s_value	t_value;

struct	s_node
{
	int		value;
	t_node	*prev;
	t_node	*next;
};

struct	s_stack
{
	int		size;
	int		self;
	t_node	*top;
	t_node	*bottom;
};

struct	s_value
{
	int	pivot_small;
	int	pivot_big;
	int	pivot_middle;
	int	ra;
	int	ra_sub;
	int	rb;
	int	pa;
	int	pb;
};

void	ft_process_p(t_stack *a, t_stack *b, char *flag);
void	ft_process_r(t_stack *target, char *flag);
void	ft_process_r_all(t_stack *a, t_stack *b);
void	ft_process_rr(t_stack *target, char *flag);
void	ft_process_rrr(t_stack *a, t_stack *b);
void	ft_process_s(t_stack *target, char *flag);
void	ft_process_ss(t_stack *a, t_stack *b);

void	ft_free_stack(t_stack *target);
void	ft_print_error(void);
void	ft_print_stack(t_stack *target);

t_value	ft_init_value(void);
t_node	*ft_init_node(void);
t_stack	*ft_init_stack(char c);

void	ft_sort_array(int *sort, int size);
void	ft_check_minmax(t_stack *stack, int *min, int *max, int r);

void	ft_check_pivot(t_stack *stack, int size, t_value *value);

void	ft_set_stack(t_stack *stack, int argc, char *argv[]);

int		ft_check_sort_a(t_stack *a, int r);
int		ft_check_sort_b(t_stack *b, int r);

t_node	*ft_stack_pop(t_stack *target);
void	ft_stack_push(t_stack *target, t_node *node);

int		ft_argv_length(char *argv);
int		ft_check_num(char *argv);
int		ft_check_argv(char *argv);
void	ft_check_stack(t_stack *stack);

void	ft_a_to_b(t_stack *a, t_stack *b, int r, int *is_b_to_a);
void	ft_a_to_b_push(t_stack *a, t_stack *b, int r, t_value *value);

void	ft_b_to_a(t_stack *a, t_stack *b, int r, int *is_b_to_a);
void	ft_b_to_a_push(t_stack *a, t_stack *b, int r, t_value *value);

void	ft_range_five(t_stack *target, t_stack *stack, int r, t_value value);

void	ft_under_three(t_stack *target, t_stack *stack, int r);
void	ft_range_two(t_stack *target, t_node *node);

void	ft_range_three(t_stack *target, t_stack *stack,
			int min_index, int max_index);

void	ft_size_three_a(t_stack *target, int min_index, int max_index);
void	ft_range_three_a(t_stack *target, t_stack *stack,
			int min_index, int max_index);

void	ft_size_three_b(t_stack *target, int min_index, int max_index);
void	ft_range_three_b(t_stack *target, t_stack *stack,
			int min_index, int max_index);
#endif
