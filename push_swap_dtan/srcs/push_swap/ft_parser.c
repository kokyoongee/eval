#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	size_t	offset;
	long	res;
	int		sign;

	offset = 0;
	res = 0;
	sign = 1;
	while (nptr[offset] == ' ' || nptr[offset] == '\n' || nptr[offset] == '\t'
		|| nptr[offset] == '\r' || nptr[offset] == '\v' || nptr[offset] == '\f')
		offset++;
	if (nptr[offset] == '-' || nptr[offset] == '+')
	{
		if (nptr[offset] == '-')
			sign = -1;
		offset++;
	}
	while (nptr[offset] >= '0' && nptr[offset] <= '9')
		res = res * 10 + (nptr[offset++] - '0');
	return (res * sign);
}

int	ft_is_valid_arg(t_list *stack, char *arg)
{
	int		i;
	long	num;

	i = 0;
	if (ft_strlen(arg) == 0)
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	num = ft_atol(arg);
	while (stack)
	{
		if (stack->content == num)
			return (0);
		stack = (stack)->next;
	}
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

char	**ft_copy_args(int argc, char **argv)
{
	char	**arr;
	int		i;
	int		j;

	arr = (char **) malloc(sizeof(char *) * (argc));
	if (!arr)
		return (NULL);
	i = 1;
	j = 0;
	while (argv[i])
	{
		arr[j] = ft_strdup(argv[i]);
		j++;
		i++;
	}
	arr[j] = NULL;
	return (arr);
}
