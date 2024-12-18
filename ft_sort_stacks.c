/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:32:04 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/26 08:54:20 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack.h"
#include "utils.h"

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rr(a, b, true);
	set_index_and_median(*a);
	set_index_and_median(*b);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
	t_stack_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rrr(a, b, true);
	set_index_and_median(*a);
	set_index_and_median(*b);
}

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->is_above_median && cheapest->target_node->is_above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->is_above_median)
		&& !(cheapest->target_node->is_above_median))
		rev_rotate_both(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target_node, 'b');
	pb(b, a, true);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	size_t	len_a;

	len_a = ft_stack_len(*a);
	if (len_a-- > 3 && ft_stack_sorted(*a) == false)
		pb(b, a, true);
	if (len_a-- > 3 && ft_stack_sorted(*a) == false)
		pb(b, a, true);
	while (len_a-- > 3 && ft_stack_sorted(*a) == false)
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index_and_median(*a);
	min_on_top(a);
}
