/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:18:34 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/09 09:10:04 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_env	*env;

	if (!(env = malloc(sizeof(*env))))
		ft_exit("Error, out of memory.", -1);
	env->pieces_list = NULL;
	parse(argc, argv, env);
	printf("Parse ended without any problem.\n");
}
