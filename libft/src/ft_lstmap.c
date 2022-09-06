/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:29:24 by elraira-          #+#    #+#             */
/*   Updated: 2022/08/27 09:40:41 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*current;

	if (!lst || !f)
		return (NULL);
	current = ft_lstnew(f(lst->content));
	first = current;
	lst = lst->next;
	while (lst)
	{
		current = ft_lstnew(f(lst->content));
		if (!current)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&first, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&first, current);
	}
	return (first);
}
