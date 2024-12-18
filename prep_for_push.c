/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_for_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:04:53 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/25 16:07:41 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	prep_for_push(t_stack_node **stack, t_stack_node *top, char name)
{
	while (*stack != top)
	{
		if (name == 'a')
		{
			if (top->is_above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (name == 'b')
		{
			if (top->is_above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}
