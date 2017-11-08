/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:42:02 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/08 16:32:44 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>

typedef struct 	s_piece
{
	char	**datas;
}				t_piece;			

typedef struct	s_fillist
{
	t_list		*next;
	t_piece		*piece;
}				t_fillist;

typedef struct s_env
{
	t_list		**pieces_list;
}				t_env;

void			check_bloc_position(t_env *env);
void			check_piece_char(t_env *env); 
void			check_all_pieces(t_env *env);
void			add_piece(char *buffer, t_env *env);
void			parse(int argc, char **argv, t_env *env); 
void			load_datas(int fd, t_env *env);
#endif
