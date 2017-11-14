/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:42:02 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/14 17:11:23 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./includes/libft.h"
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
	int					curr_grid_size;
	int					total_width;
	int					total_height;
	int					initial_grid_size;
}						t_env;

int						check_bloc_position(t_piece *piece);
int						check_piece_char(t_piece *piece);
int						check_piece_format(t_piece *piece);
int						check_all_pieces(t_env *env);
int						add_piece(char *buffer, t_env *env);
int						parse(int argc, char **argv, t_env *env);
int						load_datas(int fd, t_env *env);
int						format_piece(t_piece *piece);
int						solve(t_env *env);
int						can_place(t_env *env, t_piece *piece, int x, int y);
void					print_piece(t_piece *piece);
void					place_piece(t_env *env, t_piece *piece, int x, int y);
int						increment_value(t_env *env, int *x, int *y);
void					decrement_value(t_env *env, int *x, int *y);

#endif
