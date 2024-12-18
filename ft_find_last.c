/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:01:02 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/23 18:24:48 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack_node	*ft_find_last(t_stack_node *stack)
{
	t_stack_node	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
