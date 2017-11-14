/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:15:18 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/14 16:56:03 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		parse(int argc, char **argv, t_env *env)
{
	int		fd;

	if (argc > 2)
		return (0);
	if (argc <= 1)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if (!load_datas(fd, env))
		return (0);
	if (!check_all_pieces(env))
		return (0);
	return (1);
}

int		load_datas(int fd, t_env *env)
{
	int		data_read;
	int		nb_read;
	char	buffer[22];
	int		last_read;

	nb_read = 0;
	while ((data_read = read(fd, buffer, 21)) > 0)
	{
		buffer[data_read] = '\0';
		last_read = data_read;
		++nb_read;
		if (nb_read > 26)
			return (0);
		add_piece(buffer, env);
	}
	if (last_read == 21 || nb_read == 0)
		return (0);
	env->nb_pieces = nb_read;
	return (1);
}

int		add_piece(char *buffer, t_env *env)
{
	t_fillist	*list;
	t_fillist	*piece;

	if (!(piece = malloc(sizeof(*piece))))
		return (0);
	piece->next = NULL;
	if (!(piece->piece = malloc(sizeof(t_piece))))
		return (0);
	if (!(piece->piece->datas = ft_strsplit(buffer, '\n')))
		return (0);
	if (!env->pieces_list)
	{
		env->pieces_list = piece;
		return (1);
	}
	list = env->pieces_list;
	while (list->next)
		list = list->next;
	list->next = piece;
	return (1);
}
