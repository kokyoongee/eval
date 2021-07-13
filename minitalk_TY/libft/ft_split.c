/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telee <telee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:23:51 by telee             #+#    #+#             */
/*   Updated: 2021/05/21 13:52:03 by telee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	column(char const *s, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (s[a] && s[a] != c)
		b++;
	while (s[a])
	{
		if (s[a] == c && s[a + 1] != c && s[a + 1])
			b++;
		a++;
	}
	return (b);
}

char	*splitted(char const *s, char c, int a)
{
	int		e;
	int		f;
	char	*str;

	e = a;
	while (s[e] && s[e] != c)
		e++;
	str = malloc(sizeof(char) * ((e - a) + 1));
	if (!str)
		return (NULL);
	f = 0;
	while (a != e)
	{
		str[f] = s[a];
		f++;
		a++;
	}
	str[f] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*row;
	int		a;
	int		b;

	if (s)
		new = malloc(sizeof(char *) * (column(s, c) + 1));
	if (!s || !new)
		return (NULL);
	a = 0;
	b = 0;
	while (a < (int)ft_strlen(s))
	{
		row = splitted(s, c, a);
		if (ft_strlen(row))
		{
			new[b] = row;
			a += (ft_strlen(new[b]) + 1);
			b++;
		}
		else
			a++;
	}
	new[b] = 0;
	return (new);
}
