/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:55:57 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/30 10:56:42 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "stack.h"
#include "utils.h"
#include <stdlib.h>

static void	ft_add_to_stack(t_stack_node **stack, int n)
{
	t_stack_node	*newnode;
	t_stack_node	*last;

	if (!stack)
		return ;
	newnode = malloc(sizeof(t_stack_node));
	if (!newnode)
		return ;
	newnode->next = NULL;
	newnode->val = n;
	newnode->is_cheapest = false;
	if (!*stack)
	{
		*stack = newnode;
		newnode->prev = NULL;
	}
	else
	{
		last = ft_find_last(*stack);
		last->next = newnode;
		newnode->prev = last;
	}
}

bool	syntax_error(char *s)
{
	if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
		return (true);
	if ((*s == '+' || *s == '-') && !(s[1] >= '0' && s[1] <= '9'))
		return (true);
	while (*++s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (true);
	}
	return (false);
}

bool	check_duplicates(t_stack_node *stack, int i)
{
	if (!stack)
		return (false);
	while (stack)
	{
		if (stack->val == i)
			return (true);
		stack = stack->next;
	}
	return (false);
}

int	ft_nbrlen(char *s)
{
	int	i;

	i = 0;
	if (*s == '-' || *s == '+')
	{
		i++;
		s++;
	}
	while (*s == '0')
		s++;
	while (ft_isdigit(*s++))
		i++;
	return (i);
}

void	ft_stack_init(t_stack_node **stack, char **argv, bool splitted)
{
	int		i;
	long	temp;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			free_error(stack, argv - 1, splitted);
		temp = ft_atol(argv[i]);
		if ((temp > INT_MAX || temp < INT_MIN)
			|| ft_nbrlen(argv[i]) > 11)
			free_error(stack, argv - 1, splitted);
		if (check_duplicates(*stack, (int)temp))
			free_error(stack, argv - 1, splitted);
		ft_add_to_stack(stack, (int)temp);
		i++;
	}
}
