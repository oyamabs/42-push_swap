/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:56:00 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/30 10:55:00 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "stack.h"

void	exit_error(void);
long	ft_atol(const char *s);
char	**split(char *s, char sep);
void	ft_free_split(char **split, bool is_splitted);
void	free_error(t_stack_node **stack, char **argv, bool splitted);
int		ft_nbrlen(char *s);
bool	check_duplicates(t_stack_node *stack, int i);
bool	syntax_error(char *s);

#endif
