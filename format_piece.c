/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:51:05 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/23 07:12:00 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		has_bloc_on_line(t_piece *piece, int y)
{
	int		i;

	i = -1;
	while (piece->datas[y][++i])
		if (piece->datas[y][i] == '#')
			return (1);
	return (0);
}

int		has_bloc_on_column(t_piece *piece, int x)
{
	int		i;

	i = -1;
	while (piece->datas[++i])
		if (piece->datas[i][x] == '#')
			return (1);
	return (0);
}

void	calculate_format(t_piece *piece)
{
	int		i;
	int		j;

	piece->height = 4;
	piece->width = 4;
	i = -1;
	while (piece->datas[++i])
	{
		j = -1;
		while (piece->datas[i][++j])
			if (i == 0 && !has_bloc_on_column(piece, j))
				--piece->width;
		if (!has_bloc_on_line(piece, i))
			--piece->height;
	}
}

void	fill_piece(t_piece *piece, char **result)
{
	int		i;
	int		j;
	int		res_i;
	int		res_j;

	i = -1;
	res_i = -1;
	while (piece->datas[++i])
	{
		if (!has_bloc_on_line(piece, i))
			continue ;
		j = -1;
		++res_i;
		res_j = -1;
		while (piece->datas[i][++j])
		{
			if (!has_bloc_on_column(piece, j))
				continue ;
			++res_j;
			result[res_i][res_j] = piece->datas[i][j];
		}
	}
}

int		format_piece(t_piece *piece)
{
	int		i;
	char	**result;
	int		res_i;
	int		res_j;

	calculate_format(piece);
	if (!(result = malloc((piece->height + 1) * sizeof(*result))))
		return (0);
	i = -1;
	res_i = -1;
	res_j = -1;
	result[piece->height] = NULL;
	while (++i < piece->height)
	{
		if (!(result[i] = malloc(piece->width + 1)))
			return (0);
		result[i][piece->width] = '\0';
	}
	fill_piece(piece, result);
	free_piece_datas(piece);
	piece->datas = result;
	return (1);
}
