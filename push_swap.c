/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:10:55 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/30 10:55:38 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"
#include "sort.h"

void	sort(t_stack_node **a, t_stack_node **b)
{
	while (ft_stack_sorted(*a) == false)
	{
		if (ft_stack_len(*a) == 2)
			sa(a, true);
		else if (ft_stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
}

int	main(int argc, char **argv)
{
	bool			splitted;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	splitted = false;
	if (argc == 1)
		exit(1);
	if (argc == 2 && !argv[1][0])
		exit_error();
	else if (argc == 2)
	{
		argv = split(argv[1], ' ');
		splitted = true;
	}
	ft_stack_init(&a, argv + 1, splitted);
	ft_free_split(argv, splitted);
	sort(&a, &b);
	ft_free_stack(&a);
	return (0);
}
