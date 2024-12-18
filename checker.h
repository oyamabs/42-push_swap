/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchampio <tchampio@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:58:16 by tchampio          #+#    #+#             */
/*   Updated: 2024/11/30 09:48:27 by tchampio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/includes/libft.h"
# include "stack.h"
# include "utils.h"
# include <unistd.h>

typedef enum OPERATION_TYPE
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	ERROR = -1
}	t_operation;
char	**split(char *s, char separator);

#endif
