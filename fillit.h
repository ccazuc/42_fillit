/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:42:02 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/09 10:07:08 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct			s_piece
{
	char				**datas;
	int					width;
	int					height;
}						t_piece;

typedef struct			s_fillist
{
	struct s_fillist	*next;
	t_piece				*piece;
}						t_fillist;

typedef struct			s_env
{
	t_fillist			*pieces_list;
	char				**grid;
	int					pieces_placed;
	int					nb_pieces;
}						t_env;

void					check_bloc_position(t_piece *piece);
void					check_piece_char(t_piece *piece);
void					check_piece_format(t_piece *piece);
void					check_all_pieces(t_env *env);
void					add_piece(char *buffer, t_env *env);
void					parse(int argc, char **argv, t_env *env);
void					load_datas(int fd, t_env *env);
void					format_piece(t_piece *piece);

#endif
