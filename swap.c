/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:12:05 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/25 14:19:41 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	ft_swap(t_stack_node **h)
{
	if (!*h || !(*h)->next)
		return ;
	*h = (*h)->next;
	(*h)->prev->prev = *h;
	(*h)->prev->next = (*h)->next;
	if ((*h)->next)
		(*h)->next->prev = (*h)->prev;
	(*h)->next = (*h)->prev;
	(*h)->prev = NULL;
}

void	sa(t_stack_node **a, bool print)
{
	ft_swap(a);
	if (print == true)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	ft_swap(b);
	if (print == true)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	ft_swap(a);
	ft_swap(b);
	if (print == true)
		ft_printf("ss\n");
}
