/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:19:20 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/30 10:52:46 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>
# include <limits.h>
# include "libft/includes/libft.h"

typedef struct s_stack_node
{
	int					val;
	int					index;
	int					push_cost;
	bool				is_above_median;
	bool				is_cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// operations (sa, sb, ss, pa, pb...)
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **a, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

// stack utils
void			ft_stack_init(t_stack_node **stack, char **args, bool splitted);
bool			ft_stack_sorted(t_stack_node *stack);
size_t			ft_stack_len(t_stack_node *stack);
void			ft_free_stack(t_stack_node **a);
void			set_index_and_median(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			min_on_top(t_stack_node **a);
void			prep_for_push(t_stack_node **stack,
					t_stack_node *top, char name);
t_stack_node	*ft_find_last(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
t_stack_node	*ft_node_init(t_stack_node **stack, int n);
t_stack_node	*ft_max(t_stack_node *stack);
t_stack_node	*ft_min(t_stack_node *stack);

#endif
