/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:52:16 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/30 10:58:07 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "utils.h"

static t_operation	ft_get_operation(const char *buffer)
{
	if (ft_strncmp(buffer, "pa\n", 3) == 0)
		return (PA);
	if (ft_strncmp(buffer, "pb\n", 3) == 0)
		return (PB);
	if (ft_strncmp(buffer, "sa\n", 3) == 0)
		return (SA);
	if (ft_strncmp(buffer, "sb\n", 3) == 0)
		return (SB);
	if (ft_strncmp(buffer, "ss\n", 3) == 0)
		return (SS);
	if (ft_strncmp(buffer, "ra\n", 3) == 0)
		return (RA);
	if (ft_strncmp(buffer, "rb\n", 3) == 0)
		return (RB);
	if (ft_strncmp(buffer, "rr\n", 3) == 0)
		return (RR);
	if (ft_strncmp(buffer, "rra\n", 4) == 0)
		return (RRA);
	if (ft_strncmp(buffer, "rrb\n", 4) == 0)
		return (RRB);
	if (ft_strncmp(buffer, "rrr\n", 4) == 0)
		return (RRR);
	return (ERROR);
}

static void	do_operation(t_operation op, t_stack_node **a, t_stack_node **b)
{
	if (op == PA)
		pa(a, b, false);
	else if (op == PB)
		pb(b, a, false);
	else if (op == SA)
		sa(a, false);
	else if (op == SB)
		sb(b, false);
	else if (op == SS)
		ss(a, b, false);
	else if (op == RA)
		ra(a, false);
	else if (op == RB)
		rb(b, false);
	else if (op == RR)
		rr(a, b, false);
	else if (op == RRA)
		rra(a, false);
	else if (op == RRB)
		rrb(b, false);
	else if (op == RRR)
		rrr(a, b, false);
}

static void	check_sort(t_stack_node **a, t_stack_node **b)
{
	char		*buffer;
	t_operation	current_operation;

	buffer = get_next_line(STDIN_FILENO);
	while (buffer)
	{
		if (buffer[0] == '\n')
			break ;
		current_operation = ft_get_operation(buffer);
		free(buffer);
		if (current_operation == ERROR)
			return (ft_putstr_fd("Error\n", 2));
		do_operation(current_operation, a, b);
		buffer = get_next_line(STDIN_FILENO);
	}
	if (ft_stack_sorted(*a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(buffer);
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
	check_sort(&a, &b);
	ft_free_split(argv, splitted);
	ft_free_stack(&a);
	return (0);
}
