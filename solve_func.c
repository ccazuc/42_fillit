/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:07:38 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/14 17:09:10 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place_piece(t_env *env, t_piece *piece, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < piece->height)
	{
		j = -1;
		while (++j < piece->width)
			if (piece->datas[i][j] == '#')
				env->grid[y + i][x + j] = env->pieces_placed + 'A';
	}
}

int		increment_value(t_env *env, int *x, int *y)
{
	if (*x == env->curr_grid_size - 1)
	{
		*x = 0;
		*y = *y + 1;
		if (*y > env->curr_grid_size - 1)
			return (0);
	}
	else
		*x = *x + 1;
	return (1);
}

void	decrement_value(t_env *env, int *x, int *y)
{
	if (*x == 0)
	{
		*x = env->curr_grid_size - 1;
		*y = *y - 1;
	}
	else
		*x = *x - 1;
}
