/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:23:13 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/25 14:27:15 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	ft_rotate(t_stack_node **s)
{
	t_stack_node	*last_node;

	if (!*s || !(*s)->next)
		return ;
	last_node = ft_find_last(*s);
	last_node->next = *s;
	*s = (*s)->next;
	(*s)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	ft_rotate(a);
	if (print == true)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	ft_rotate(b);
	if (print == true)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	ft_rotate(a);
	ft_rotate(b);
	if (print == true)
		ft_printf("rr\n");
}
