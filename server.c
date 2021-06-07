/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamghoug <bamghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:25:07 by bamghoug          #+#    #+#             */
/*   Updated: 2021/06/07 20:35:37 by bamghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	recieve(int c)
{
	printf("sig = %d\n", c);
	return ;
}

int main()
{
    int pid;

    pid = getpid();
    
    printf("pid = %d\n", pid);
	signal(SIGUSR1, recieve);
	signal(SIGUSR2, recieve);
	while (1)
    	pause();
    return (0);
}