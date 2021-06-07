/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:30:30 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/07 20:38:49 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

int		ft_atoi(const char *str)
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

int main(int ac, char **av)
{
	struct __sigaction handle;
    struct sigaction test;
    int		sigempty;
	int		pid;
    
	sigempty = sigemptyset(&test.sa_mask);
	test.sa_flags = 0;
	if (ac < 3)
	{
		write(1, "Parameters Error\n", ft_strlen("Parameters Error\n"));
		return (1);
	}
	else
	{
		pid = ft_atoi(av[1]);
		printf("pid = %d\n", pid);
		kill(pid, SIGUSR1);
	}
}