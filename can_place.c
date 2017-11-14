/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:24:49 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/14 15:41:21 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_place(t_env *env, t_piece *piece, int x, int y)
{
	int		i;
	int		j;

	if (x + piece->width >= env->curr_grid_size || y + piece->height >=
		env->curr_grid_size)
		return (0);
	i = -1;
	while (piece->datas[++i])
	{
		j = -1;
		while (piece->datas[i][++j])
			if (piece->datas[i][j] == '#' && env->grid[y + i][j + x] != '.')
				return (0);
	}
	return (1);
}
