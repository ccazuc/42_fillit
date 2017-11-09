/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:57:39 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/09 11:17:21 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_all_pieces(t_env *env)
{
	t_fillist	*list;

	list = env->pieces_list;
	while (list)
	{
		check_piece_char(list->piece);
		check_bloc_position(list->piece);
		check_piece_format(list->piece);
		format_piece(list->piece);
		list = list->next;
	}
}

void	check_piece_format(t_piece *piece)
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
			ft_exit("Error, invalid piece format.", -1);
	}
	if (i != 4)
		ft_exit("Error, invalid piece format.", -1);
}

void	check_piece_char(t_piece *piece)
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
				ft_exit("Error, invalid character in a piece.", -1);
	}
	if (nb_bloc != 4)
		ft_exit("Error, invalid number of bloc in a piece.", -1);
}

void	check_bloc_position(t_piece *piece)
{
	int		i;
	int		j;

	i = -1;
	while (piece->datas[++i])
	{
		j = -1;
		while (piece->datas[i][++j])
			if (piece->datas[i][j] == '#')
			{
				if ((i > 0 && piece->datas[i - 1][j] == '#') || (i < 3 &&
					piece->datas[i + 1][j] == '#') || (j > 0 &&
						piece->datas[i][j - 1] == '#') || (j < 3 &&
							piece->datas[i][j + 1] == '#'))
				{
					continue ;
				}
				else
					ft_exit("Error, invalid piece format.", -1);
			}
	}
}
