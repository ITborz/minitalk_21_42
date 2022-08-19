/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:57:42 by bkristen          #+#    #+#             */
/*   Updated: 2021/10/25 18:47:13 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_length;
	size_t	dst_length;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	i = 0;
	if (dstsize <= dst_length)
		return (src_length + dstsize);
	while (dst[i] != '\0' && i < dstsize - 1)
		i++;
	while (i < dstsize - 1 && *src)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dst_length + src_length);
}
