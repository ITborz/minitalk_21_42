/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:44:47 by bkristen          #+#    #+#             */
/*   Updated: 2021/10/25 18:37:54 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		l;

	tmp = (char *)s;
	l = ft_strlen(tmp);
	if (c == 0)
		return (tmp + l);
	while (l >= 0)
	{
		if (tmp[l] == (char)c)
			return (tmp + l);
		l--;
	}
	return (NULL);
}
