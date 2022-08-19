/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:03:58 by bkristen          #+#    #+#             */
/*   Updated: 2021/10/25 18:49:21 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*tmp;
	char	*ptr;

	tmp = (char *)s1;
	ptr = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (tmp[i] != ptr[i])
			return ((unsigned char)tmp[i] - (unsigned char)ptr[i]);
		i++;
	}
	return (0);
}
