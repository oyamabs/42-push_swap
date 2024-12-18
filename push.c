/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:59:02 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/25 17:56:43 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	ft_push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*pushed_node;

	if (!*src)
		return ;
	pushed_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	pushed_node->prev = NULL;
	if (!*dst)
	{
		*dst = pushed_node;
		pushed_node->next = NULL;
	}
	else
	{
		pushed_node->next = *dst;
		pushed_node->next->prev = pushed_node;
		*dst = pushed_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	ft_push(a, b);
	if (print == true)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	ft_push(b, a);
	if (print == true)
		ft_printf("pb\n");
}
