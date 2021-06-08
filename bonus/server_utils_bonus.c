/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:41:52 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/08 17:37:24 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_index(int i)
{
	if (i == 7)
		return (128);
	if (i == 6)
		return (64);
	if (i == 5)
		return (32);
	if (i == 4)
		return (16);
	if (i == 3)
		return (8);
	if (i == 2)
		return (4);
	if (i == 1)
		return (2);
	return (1);
}

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	d = dst;
	s = src;
	if (d == s)
		return (dst);
	while (n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	if (s1 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	p = malloc((j + i + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		p[i] = s1[i];
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	char	*res;
	int		i;

	i = ft_strlen(s1);
	p = malloc((i + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	res = ft_memcpy(p, s1, (i + 1));
	return (res);
}
