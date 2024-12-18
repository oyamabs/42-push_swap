/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:44:53 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/25 10:46:20 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

size_t	ft_stack_len(t_stack_node *stack)
{
	size_t	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
