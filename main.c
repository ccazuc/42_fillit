/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:18:34 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/08 16:30:21 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_env	*env;

	if (!(env = malloc(sizeof(*env))))
		ft_exit("Error, out of memory.");
	parse(argc, argv, env);	
}
