/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:35:32 by mde-figu          #+#    #+#             */
/*   Updated: 2021/12/12 17:35:34 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*copy;

	new = 0;
	while (lst)
	{
		copy = ft_lstnew(f(lst->content));
		if (!(copy))
		{
			ft_lstclear(&new, del);
			return (new);
		}
		ft_lstadd_back(&new, copy);
		lst = lst->next;
	}
	return (new);
}
