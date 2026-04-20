/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos-e <aramos-e@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:01:32 by aramos-e          #+#    #+#             */
/*   Updated: 2026/04/20 14:51:02 by aramos-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr_list;

	ptr_list = malloc(sizeof(t_list));
	if (!ptr_list)
		return (NULL);
	ptr_list ->content = content;
	ptr_list ->next = NULL;
	return (ptr_list);
}
