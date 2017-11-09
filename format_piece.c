/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:51:05 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/09 11:18:02 by ccazuc           ###   ########.fr       */
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

void	print_piece(t_piece *piece)
{
	int		i;
	int		j;

	i = -1;
	while (piece->datas[++i])
	{
		j = -1;
		while (piece->datas[i][++j])
			ft_putchar(piece->datas[i][j]);
		ft_putchar('\n');
	}
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

void	format_piece(t_piece *piece)
{
	int		i;
	int		j;
	char	**result;
	int		res_i;
	int		res_j;

	calculate_format(piece);
	if (!(result = malloc((piece->height + 1) * sizeof(*result))))
		ft_exit("Error, out of memory.", -1);
	i = -1;
	res_i = -1;
	res_j = -1;
	result[piece->height] = NULL;
	while (++i < piece->height)
	{	
		if (!(result[i] = malloc(piece->width + 1)))
			ft_exit("Error, out of memory.", -1);
		result[i][piece->width] = '\0';
	}
	printf("-----------------------------------------\nBefore:\n");
	printf("height: %d, width: %d\n", piece->height, piece->width);
	print_piece(piece);
	i = -1;
	while (piece->datas[++i])
	{
		//printf("check_line: %d\n", i);
		if (!has_bloc_on_line(piece, i))
			continue ;
		//printf("line: %d has block\n", i);
		j = -1;
		++res_i;
		res_j = -1;
		while (piece->datas[i][++j])
		{
			//printf("check_column\n");
			if (!has_bloc_on_column(piece, j))
				continue ;
			++res_j;
			//printf("res_i: %d, res_j: %d, i: %d, j: %d\n", res_i, res_j, i, j);
			result[res_i][res_j] = piece->datas[i][j];
		}
	}
	free(piece->datas);
	piece->datas = result;
	printf("After:\n");
	print_piece(piece);
}
