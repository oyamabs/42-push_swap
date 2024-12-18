/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:52:57 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/26 12:30:13 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_free_stack(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!a)
		return ;
	current = *a;
	while (current)
	{
		tmp = current->next;
		current->val = 0;
		free(current);
		current = tmp;
	}
	*a = NULL;
}
