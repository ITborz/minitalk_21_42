/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:54:02 by bkristen          #+#    #+#             */
/*   Updated: 2021/10/27 19:11:58 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntword(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			cnt++;
			while (*s && (*s != c))
				s++;
		}
	}
	return (cnt);
}

static void	*ft_free(char **dosh, size_t len)
{
	while (len--)
		free(dosh[len]);
	free(dosh);
	return (NULL);
}

static char	**ft_str(char **tab, char const *s, char c)
{
	unsigned int		j;
	unsigned int		len;
	const char			*start;

	j = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		start = (char *)s;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		if (*(s - 1) != c)
		{
			tab[j++] = ft_substr(start, 0, len);
			if (tab == NULL)
				ft_free(tab, j);
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(*tab) * (ft_cntword(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	return (ft_str(tab, s, c));
}
