/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:16:03 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/26 08:50:15 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// Sets the target nodes of every node of a
void	set_target_nodes_a(t_stack_node *a, t_stack_node *b)
{
	long			best;
	t_stack_node	*current_b;
	t_stack_node	*current_target;

	while (a)
	{
		best = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->val < a->val && current_b->val > best)
			{
				best = current_b->val;
				current_target = current_b;
			}
			current_b = current_b->next;
		}
		if (best == LONG_MIN)
			a->target_node = ft_max(b);
		else
			a->target_node = current_target;
		a = a->next;
	}
}

// Calculate the number of instructions to push said node where it belongs
// (push_cost) of stack.
// Based on the index, if the node is above
// the median or not and length of a and b
void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(a);
	len_b = ft_stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->is_above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->is_above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	set_index_and_median(a);
	set_index_and_median(b);
	set_target_nodes_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
