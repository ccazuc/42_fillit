/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 06:34:55 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/08 07:23:09 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result;

	if (!(result = malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
		((unsigned char*)result)[i] = (*f)((unsigned int)i, s[i]);
	((unsigned char*)result)[i] = '\0';
	return (result);
}
