/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:57:39 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/14 17:07:20 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_all_pieces(t_env *env)
{
	t_fillist	*list;

	list = env->pieces_list;
	while (list)
	{
		if (!check_piece_char(list->piece) ||
			!check_piece_format(list->piece) ||
			!check_bloc_position(list->piece) ||
			!format_piece(list->piece))
			return (0);
		env->total_width += list->piece->width;
		env->total_height += list->piece->height;
		list = list->next;
	}
	env->initial_grid_size = 0;
	return (1);
}

int		check_piece_format(t_piece *piece)
{
	int		i;
	int		j;

	i = -1;
	while (piece->datas[++i])
	{
		j = 0;
		while (piece->datas[i][j])
			++j;
		if (j != 4)
			return (0);
	}
	if (i != 4)
		return (0);
	return (1);
}

int		check_piece_char(t_piece *piece)
{
	int		i;
	int		j;
	int		nb_bloc;

	i = -1;
	nb_bloc = 0;
	while (piece->datas[++i])
	{
		j = -1;
		while (piece->datas[i][++j])
			if (piece->datas[i][j] == '#')
				++nb_bloc;
			else if (piece->datas[i][j] != '.')
				return (0);
	}
	if (nb_bloc != 4)
		return (0);
	return (1);
}

int		get_nb_adjacent(t_piece *piece, int i, int j)
{
	int		result;

	result = 0;
	if (i > 0 && piece->datas[i - 1][j] == '#')
		++result;
	if (i < 3 && piece->datas[i + 1][j] == '#')
		++result;
	if (j > 0 && piece->datas[i][j - 1] == '#')
		++result;
	if (j < 3 && piece->datas[i][j + 1] == '#')
		++result;
	return (result);
}

int		check_bloc_position(t_piece *piece)
{
	int		i;
	int		j;
	int		nb_link;

	i = -1;
	nb_link = 0;
	while (piece->datas[++i])
	{
		j = -1;
		while (piece->datas[i][++j])
			if (piece->datas[i][j] == '#')
			{
				if (get_nb_adjacent(piece, i, j) > 0)
				{
					nb_link = get_nb_adjacent(piece, i, j) ==
					1 ? nb_link + 1 : nb_link;
					continue ;
				}
				else
					return (0);
			}
	}
	if (nb_link != 2 && nb_link != 3 && nb_link != 0)
		return (0);
	return (1);
}
