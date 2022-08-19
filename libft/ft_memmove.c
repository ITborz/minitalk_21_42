/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 07:56:47 by bkristen          #+#    #+#             */
/*   Updated: 2021/10/25 19:53:35 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*str;
	const unsigned char	*ptr;

	str = dst;
	ptr = src;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			str[i] = ptr[i];
			i++;
		}
	}
	else if (dst > src)
	{
		i = len ;
		while (i > 0)
		{
			i--;
			str[i] = ptr[i];
		}
	}
	return (dst);
}
