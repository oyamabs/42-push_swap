/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:59:47 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/26 09:55:39 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack_node	*ft_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*current_max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->val > max)
		{
			max = stack->val;
			current_max = stack;
		}
		stack = stack->next;
	}
	return (current_max);
}

t_stack_node	*ft_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*current_min;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->val < min)
		{
			min = stack->val;
			current_min = stack;
		}
		stack = stack->next;
	}
	return (current_min);
}
