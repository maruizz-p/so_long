/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoyverdito <zoyverdito@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:10:46 by zoyverdito        #+#    #+#             */
/*   Updated: 2023/05/07 21:13:01 by zoyverdito       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (lst == NULL || f == NULL)
	{
		return ;
	}
	current = lst;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}
