/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:27:17 by bkristen          #+#    #+#             */
/*   Updated: 2021/10/23 18:29:07 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t	ft_get_len(int n)
{
	size_t	size_n;

	size_n = 0;
	if (n <= 0)
		size_n++;
	while (n)
	{
		size_n++;
		n /= 10;
	}
	return (size_n);
}

char	*ft_itoa(int n)
{
	size_t	size_n;
	char	*str;

	size_n = ft_get_len(n);
	str = (char *)malloc(size_n + 1);
	if (!str)
		return (0);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = '0';
	str[size_n] = '\0';
	while (n)
	{
		str[size_n - 1] = n % 10 + '0';
		size_n--;
		n /= 10;
	}
	return (str);
}
