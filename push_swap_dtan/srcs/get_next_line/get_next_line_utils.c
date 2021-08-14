#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_strdel(char **ptr)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_strnew(size_t size)
{
	size_t	offset;
	char	*str;

	offset = 0;
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (offset < size + 1)
	{
		*(char *)(str + offset) = 0;
		offset++;
	}
	return (str);
}
