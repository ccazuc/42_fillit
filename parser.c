/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:15:18 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/09 08:41:24 by ccazuc           ###   ########.fr       */
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
		ft_exit("Error, file not found", -1);
	load_datas(fd, env);
	check_all_pieces(env);
}

void	load_datas(int fd, t_env *env)
{
	int		data_read;
	int		nb_read;
	char	buffer[22];

	printf("read start\n");
	nb_read = 0;
	while ((data_read = read(fd, buffer, 21)) > 0)
	{
		printf("read_while start\n");
		buffer[data_read] = '\0';
		++nb_read;
		if (nb_read > 26)
			ft_exit("Error, too many tetriminos.", -1);
		printf("add_called\n");
		add_piece(buffer, env);
	}
	printf("read end\n");
}

void	add_piece(char *buffer, t_env *env)
{
	t_fillist	*list;
	t_fillist	*piece;

	printf("add_piece\n");
	if (!(piece = malloc(sizeof(*piece))))
		ft_exit("Error, out of memory.", -1);
	piece->next = NULL;
	printf("first malloc done\n");
	if (!(piece->piece = malloc(sizeof(t_piece))))
		ft_exit("Error, out of memory", -1);
	printf("second malloc done\n");
	if (!(piece->piece->datas = ft_strsplit(buffer, '\n')))
		ft_exit("Error, out of memory", -1);
	printf("%p\n", piece->piece->datas);
	printf("third malloc done\n");
	if (!env->pieces_list)
	{
		printf("no_pieces_list\n");
		env->pieces_list = piece;
		return ;
	}
	printf("post_if\n");
	list = env->pieces_list;
	printf("add_piece malloc done\n");
	while (list->next)
	{
		list = list->next;
		printf("bla\n");
	}
	list->next = piece;
	printf("list->next->piece: %p, list: %p, list->next: %p\n", list->next->piece->datas, list, list->next);
}
