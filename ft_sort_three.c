/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:05:44 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/26 09:54:58 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "sort.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*biggest;

	biggest = ft_max(*stack);
	if (biggest == *stack)
		ra(stack, true);
	else if ((*stack)->next == biggest)
		rra(stack, true);
	if ((*stack)->val > (*stack)->next->val)
		sa(stack, true);
}
