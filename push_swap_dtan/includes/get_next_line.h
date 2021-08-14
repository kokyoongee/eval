#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

void	ft_strdel(char **ptr);

char	*ft_strnew(size_t size);

char	*get_next_line(int fd);

#endif
