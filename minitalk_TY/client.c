#include "minitalk.h"

void	msgreceived(int signo)
{
	if (signo == SIGUSR1)
		ft_putstr(GREEN"Message received and printed ✔✔✔\n"RESET);
}

void	send_sig(int pid, char *s, size_t len)
{
	size_t	i;
	int		bits;
	char	c;
	int		sent;

	ft_putstr(CYAN"Sending message...\n"RESET);
	i = 0;
	while (i <= len)
	{
		c = s[i];
		bits = 7;
		while (bits >= 0)
		{
			if ((c >> bits) & 1)
				sent = kill(pid, SIGUSR2);
			else
				sent = kill(pid, SIGUSR1);
			bits--;
			usleep(100);
		}
		i++;
	}
	if (sent != 0)
		ft_putstr(RED"Error, server doesn't exist\n"RESET);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	if (argc == 3)
	{
		sa.sa_flags = 0;
		sa.sa_handler = msgreceived;
		if (sigaction(SIGUSR1, &sa, NULL))
			ft_putstr("no");
		pid = ft_atoi(argv[1]);
		send_sig(pid, argv[2], ft_strlen(argv[2]));
	}
	else
		ft_putstr(YELLOW"Usage: [./client][pid][message]\n"RESET);
}
