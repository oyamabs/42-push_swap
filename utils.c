/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:23:40 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/30 10:58:38 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "stack.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_free_split(char **split, bool is_splitted)
{
	int		i;
	char	*current;

	if (!is_splitted)
		return ;
	i = 0;
	current = split[i];
	while (current != NULL)
	{
		free(current);
		i++;
		current = split[i];
	}
	free(split);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_error(t_stack_node **a, char **argv, bool splitted)
{
	if (splitted)
		ft_free_split(argv, splitted);
	ft_free_stack(a);
	exit_error();
}
