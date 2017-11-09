/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:15:18 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/09 11:17:27 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	parse(int argc, char **argv, t_env *env)
{
	int		fd;

	if (argc > 2)
		ft_exit("Error, too many arguments.", -1);
	if (argc <= 1)
		ft_exit("Error, not enough arguments.", -1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_exit("Error, file not found.", -1);
	printf("file: %s, fd: %d\n", argv[1], fd);
	load_datas(fd, env);
	check_all_pieces(env);
}

void	load_datas(int fd, t_env *env)
{
	int		data_read;
	int		nb_read;
	char	buffer[22];

	nb_read = 0;
	while ((data_read = read(fd, buffer, 21)) > 0)
	{
		buffer[data_read] = '\0';
		++nb_read;
		if (nb_read > 26)
			ft_exit("Error, too many tetriminos.", -1);
		add_piece(buffer, env);
	}
	env->nb_pieces = nb_read;
}

void	add_piece(char *buffer, t_env *env)
{
	t_fillist	*list;
	t_fillist	*piece;

	if (!(piece = malloc(sizeof(*piece))))
		ft_exit("Error, out of memory.", -1);
	piece->next = NULL;
	if (!(piece->piece = malloc(sizeof(t_piece))))
		ft_exit("Error, out of memory.", -1);
	if (!(piece->piece->datas = ft_strsplit(buffer, '\n')))
		ft_exit("Error, out of memory.", -1);
	if (!env->pieces_list)
	{
		env->pieces_list = piece;
		return ;
	}
	list = env->pieces_list;
	while (list->next)
		list = list->next;
	list->next = piece;
}
