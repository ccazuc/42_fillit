/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 05:51:21 by ccazuc            #+#    #+#             */
/*   Updated: 2017/11/07 19:06:24 by ccazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	tmp[n];
	size_t			i;

	i = 0;
	while (i < n)
	{
		tmp[i] = ((unsigned char*)src)[i];
		++i;
	}
	i = 0;
	while (i < n)
	{
		((unsigned char*)dest)[i] = tmp[i];
		++i;
	}
	return (dest);
}
