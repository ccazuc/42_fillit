/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:18:34 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/23 06:50:07 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_env	*env;

	if (!(env = malloc(sizeof(*env))))
	{
		ft_putstr("error\n");
		return (-1);
	}
	env->pieces_list = NULL;
	if (!parse(argc, argv, env))
	{
		ft_putstr("error\n");
		return (-1);
	}
	if (!solve(env))
	{
		ft_putstr("error\n");
		return (-1);
	}
	return (0);
}
