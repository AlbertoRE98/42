

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr_list;

	if (!content)
		return (NULL);
	ptr_list = malloc(sizeof(t_list));
	if (!ptr_list)
		return (NULL);
	ptr_list ->content = content;
	ptr_list ->next = NULL;
	return (ptr_list);
}
