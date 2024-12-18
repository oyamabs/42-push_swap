/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:38:05 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/26 08:55:09 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// Sets index for every node
// Sets if the median is above or below the current node
void	set_index_and_median(t_stack_node *s)
{
	int	i;
	int	median;

	i = 0;
	if (!s)
		return ;
	median = ft_stack_len(s) / 2;
	while (s)
	{
		s->index = i;
		if (i <= median)
			s->is_above_median = true;
		else
			s->is_above_median = false;
		s = s->next;
		i++;
	}
}

// Defines if node is the cheapest or not based on push_cost val
void	set_cheapest(t_stack_node *s)
{
	long			cheapest_val;
	t_stack_node	*current_cheapest;

	if (!s)
		return ;
	cheapest_val = LONG_MAX;
	while (s)
	{
		if (s->push_cost < cheapest_val)
		{
			current_cheapest = s;
			cheapest_val = s->push_cost;
		}
		s = s->next;
	}
	current_cheapest->is_cheapest = true;
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->is_cheapest == true)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	min_on_top(t_stack_node **a)
{
	while ((*a)->val != ft_min(*a)->val)
	{
		if (ft_min(*a)->is_above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}
