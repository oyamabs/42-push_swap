/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:28:41 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/25 14:32:59 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "stack.h"

static void	ft_rev_rotate(t_stack_node **s)
{
	t_stack_node	*last_node;

	if (!*s || !(*s)->next)
		return ;
	last_node = ft_find_last(*s);
	last_node->prev->next = NULL;
	last_node->next = *s;
	last_node->prev = NULL;
	*s = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, bool print)
{
	ft_rev_rotate(a);
	if (print == true)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	ft_rev_rotate(b);
	if (print == true)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	if (print == true)
		ft_printf("rrr\n");
}
