/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:12:43 by bkristen          #+#    #+#             */
/*   Updated: 2022/02/09 11:47:31 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	sig_error(void)
{
	ft_putendl_fd("signal error", 1);
	exit(EXIT_FAILURE);
}

static void	my_handler(int signum, siginfo_t *siginfo, void *oldact)
{
	static unsigned char	character = 0;
	static pid_t			pid = 0;
	static size_t			bit = 8;

	oldact = NULL;
	if (pid != siginfo->si_pid)
	{
		pid = siginfo->si_pid;
		character = 0;
		bit = 8;
	}
	bit--;
	if (signum == SIGUSR2)
		character |= 0x01 << bit;
	if (bit == 0)
	{
		write(1, &character, 1);
		character = 0;
		bit = 8;
	}
	usleep(160);
	if (kill(pid, SIGUSR2) == -1)
		write(1, "Error: Invalid signal!\n", 24);
}

int	main(void)
{
	struct sigaction	s_act;

	write(1, "PID ", 4);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	s_act.sa_flags = SA_SIGINFO;
	s_act.sa_sigaction = my_handler;
	if (sigaction(SIGUSR1, &s_act, NULL) == -1)
		sig_error();
	if (sigaction(SIGUSR2, &s_act, NULL) == -1)
		sig_error();
	while (1)
		pause();
	return (0);
}
