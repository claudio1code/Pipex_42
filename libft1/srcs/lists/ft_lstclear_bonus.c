/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:05:55 by clados-s          #+#    #+#             */
/*   Updated: 2025/07/31 13:49:54 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*actualy;

	if (!del || !*lst)
		return ;
	actualy = *lst;
	temp = actualy->next;
	while (actualy && actualy->next)
	{
		ft_lstdelone(actualy, del);
		actualy = temp;
		temp = actualy->next;
	}
	if (actualy)
	{
		ft_lstdelone(actualy, del);
	}
	*lst = NULL;
}
