#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*temp;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		temp = current->next;
		ft_lstdelone(current);
		current = temp;
	}
	*lst = NULL;
}
