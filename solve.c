/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 09:40:55 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/14 17:10:24 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_piece(t_env *env, t_piece *piece, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < piece->height)
	{
		j = -1;
		while (++j < piece->width)
			if (piece->datas[i][j] == '#')
				env->grid[y + i][x + j] = '.';
	}
}

int		generate_grid(t_env *env, int dim)
{
	int		i;
	int		j;

	if (!(env->grid = malloc(dim * sizeof(*env->grid))))
		return (0);
	i = -1;
	while (++i < dim)
	{
		if (!(env->grid[i] = malloc(dim)))
			return (0);
		j = -1;
		while (++j < dim)
			env->grid[i][j] = '.';
	}
	return (1);
}

void	print_result(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->curr_grid_size - 1)
	{
		j = -1;
		while (++j < env->curr_grid_size - 1)
			printf("%c", env->grid[i][j]);
		printf("\n");
	}
}

int		recurse(t_env *env, t_fillist *list)
{
	int		i;
	int		j;

	if (!list)
		return (1);
	i = -1;
	while (++i < env->curr_grid_size)
	{
		j = -1;
		while (++j < env->curr_grid_size)
		{
			if (can_place(env, list->piece, j, i))
			{
				place_piece(env, list->piece, j, i);
				env->pieces_placed++;
				if (recurse(env, list->next))
					return (1);
				remove_piece(env, list->piece, j, i);
				env->pieces_placed--;
			}
		}
	}
	return (0);
}

int		solve(t_env *env)
{
	int			i;
	int			max_size;
	t_fillist	*list;

	max_size = 20;
	i = 0;
	list = env->pieces_list;
	while (list)
		list = list->next;
	list = env->pieces_list;
	while (++i < max_size)
	{
		env->curr_grid_size = i;
		env->pieces_placed = 0;
		if (!generate_grid(env, i))
			return (0);
		if (recurse(env, env->pieces_list))
		{
			print_result(env);
			return (1);
		}
	}
	return (1);
}
