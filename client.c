/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:30:30 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/08 18:19:42 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	send_msg(char **av, int pid)
{
	int	i;
	int	ret;

	i = 2;
	ret = 0;
	while (av[i] != NULL)
	{
		ret = msg(av[i], pid);
		if (ret != 0)
			return (ret);
		if (av[i + 1] != NULL)
			convert_to_bin(32, pid);
		i++;
	}
	convert_to_bin(10, pid);
	return (ret);
}

int	main (int ac, char **av)
{
	int		pid;

	if (ac < 3)
	{
		write(1, "Parameters Error\n", ft_strlen("Parameters Error\n"));
		return (1);
	}
	else
	{
		pid = ft_atoi(av[1]);
		if (send_msg(av, pid) != 0)
			write(1, "Error!\n", 7);
	}
	return (0);
}
