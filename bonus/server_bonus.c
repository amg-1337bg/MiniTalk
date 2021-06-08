/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:25:07 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/08 17:37:18 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = n * -1;
	}
	else
		num = (unsigned int)n;
	if (num == 0)
		ft_putchar_fd(num + '0', fd);
	if (num > 0 && num <= 9)
		ft_putchar_fd(num + '0', fd);
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd((num % 10) + '0', fd);
	}
}

char	bin_to_dec(char *str)
{
	int	i;
	int	c;
	int	j;

	i = 0;
	c = 0;
	j = 7;
	while (i < 8)
	{
		if (str[i] == '1')
			c += ft_index(j);
		i++;
		j--;
	}
	return ((char)c);
}

void	recieve(int c)
{
	static char	*str;
	char		*tmp;
	char		toprint;

	if (str == NULL)
		str = ft_strdup("");
	if (c == SIGUSR1)
	{
		tmp = str;
		str = ft_strjoin(str, "0\0");
		free (tmp);
	}
	else
	{
		tmp = str;
		str = ft_strjoin(str, "1\0");
		free(tmp);
	}
	if (ft_strlen(str) == 8)
	{
		toprint = bin_to_dec(str);
		write(1, &toprint, 1);
		free (str);
		str = NULL;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "server pid is: ", ft_strlen("server pid is: "));
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, recieve);
	signal(SIGUSR2, recieve);
	while (1)
		pause();
	return (0);
}
