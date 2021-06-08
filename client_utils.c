/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:51:22 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/08 18:23:37 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (*str == 32 || *str == 9 || *str == 11
		|| *str == 12 || *str == 13 || *str == 10)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i = 1;
		str++;
	}
	if (*str < 48 && *str > 57)
		return (0);
	while (*str >= 48 && *str <= 57)
	{
		j = j * 10 + *str - '0';
		str++;
	}
	if (i == 1)
		return (j * -1);
	return (j);
}

void	ft_memset(int *i)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		i[j] = 0;
		j++;
	}
}

int	convert_to_bin(int c, int pid)
{
	int	i[8];
	int	j;
	int	ret;

	j = 7;
	ret = 0;
	ft_memset(i);
	while (j >= 0)
	{
		if (c & (1 << j))
		{
			ret = kill(pid, SIGUSR2);
			if (ret != 0)
				break ;
		}
		else
		{
			ret = kill(pid, SIGUSR1);
			if (ret != 0)
				break ;
		}
		j--;
		usleep(100);
	}
	return (ret);
}

int	msg(char *msg, int pid)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	while (msg[++i] != '\0')
	{
		ret = convert_to_bin(msg[i], pid);
		if (ret != 0)
			break ;
	}
	return (ret);
}
