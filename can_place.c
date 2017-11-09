/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:24:49 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/09 14:30:32 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		can_place(t_env *env, t_piece piece, int x, int y)
{
	int		i;
	int		j;

	if (x + piece->width > env->total_width || y + piece->height >
		env->total_height)
		return (0);
	i = -1;
	while (piece->datas[++i])
	{
		j = -1;
		while (piece->datas[i][++j])
			if (piece->datas[i][j] == '#' && env->grid[x + i][j + y] == '#')
				return (0);
	}
	return (1);
}
