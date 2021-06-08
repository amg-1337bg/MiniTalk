/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:23:16 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/08 18:22:48 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	*if_neg(int n)
{
	char			*c;
	unsigned int	num;
	int				i;

	num = (unsigned int)(n * -1);
	n = n * -1;
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	c = malloc((i + 2) * sizeof(char));
	if (c == NULL)
		return (NULL);
	i--;
	c[i + 2] = '\0';
	while ((i + 1) > 0)
	{
		c[i + 1] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	c[i + 1] = '-';
	return (c);
}

char	*if_pos(int n)
{
	char	*c;
	long	num;
	int		i;
	int		j;

	num = (long)n;
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	c = malloc((i + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	i--;
	j = i + 1;
	while (i >= 0)
	{
		c[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	c[j] = '\0';
	return (c);
}

char	*ft_itoa(int n)
{
	char	*c;

	if (n >= 0 && n <= 9)
	{
		c = malloc(2 * sizeof(char));
		if (c == NULL)
			return (NULL);
		c[0] = n + '0';
		c[1] = '\0';
	}
	if (n < 0)
		c = if_neg(n);
	if (n > 9)
		c = if_pos(n);
	return (c);
}
