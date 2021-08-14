#include "push_swap.h"

void	ft_push_stack(t_list **stack, t_list *el)
{
	t_list	*temp;

	temp = *stack;
	el->next = temp;
	*stack = el;
}

t_list	*ft_pop_stack(t_list **stack)
{
	t_list	*el;
	t_list	*temp;

	if (!stack || !(*stack))
		return (NULL);
	el = ft_lstnew((*stack)->content);
	temp = (*stack)->next;
	ft_lstdelone(*stack);
	*stack = temp;
	return (el);
}

void	ft_rotate_stack(t_list **stack)
{
	t_list	*top;

	if (!stack || !(*stack))
		return ;
	top = ft_pop_stack(stack);
	ft_lstadd_back(stack, top);
}

void	ft_reverse_rotate_stack(t_list **stack)
{
	t_list	*last;
	t_list	*temp;
	t_list	*ptr;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	temp = *stack;
	ptr = *stack;
	while (ptr->next->next)
		ptr = ptr->next;
	ptr->next = NULL;
	last->next = temp;
	*stack = last;
}

void	ft_swap_stack(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = ft_pop_stack(stack);
	second = ft_pop_stack(stack);
	ft_lstadd_front(stack, first);
	ft_lstadd_front(stack, second);
}
