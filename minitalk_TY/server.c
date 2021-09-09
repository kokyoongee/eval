#include "minitalk.h"
#include <stdio.h>

void receive_sig(int signo, siginfo_t *info, void *context)
{
	static char c;
	static int bit;
	static int first;

	(void)context;
	if (first == OFF)
	{
		ft_putstr(GREEN "Incoming message : \033[0m\n" RESET);
		first = ON;
	}
	c = (c << 1) + (signo & 1);
	if (bit++ == 7)
	{
		write(1, &c, 1);
		if (c == 0)
		{
			kill(info->si_pid, SIGUSR1);
			ft_putstr(PURPLE "\n--Message successfully printed--\n" RESET);
			first = OFF;
		}
		c = 0;
		bit = 0;
	}
}

int main(void)
{
	struct sigaction sa;

	ft_putstr(CYAN "server pid : " YELLOW);
	ft_putnbr(getpid());
	ft_putstr(RESET);
	ft_putchar('\n');
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_sig;
	while (1)
	{
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
		pause();
	}
}
