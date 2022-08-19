/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkristen <bkristen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:12:52 by bkristen          #+#    #+#             */
/*   Updated: 2022/02/09 11:47:39 by bkristen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	usage(void)
{
	write(1, "____________________________________\n", 38);
	write(1, "Wrong number of arguments\n", 27);
	write(1, "Make sure you launched server\n", 31);
	write(1, "Write: ./client [pid] [your message]\n", 38);
	write(1, "____________________________________\n", 38);
}

static void	sig_error(void)
{
	ft_putendl_fd("signal error", 1);
	exit(EXIT_FAILURE);
}

static void	ft_my_handler(int signum)
{
	(void)signum;
}

static void	my_sender(int pid, char *str)
{
	size_t	current_bit;
	size_t	i;

	i = 0;
	while (str[i])
	{
		current_bit = 8;
		while (current_bit--)
		{
			if ((str[i] >> current_bit) & 0x01)
			{
				if (kill(pid, SIGUSR2) == -1)
					sig_error();
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					sig_error();
			}
			pause();
			usleep(160);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
	{
		usage();
		return (-1);
	}
	sa.sa_handler = ft_my_handler;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		sig_error();
	my_sender(ft_atoi(argv[1]), argv[2]);
	return (0);
}
