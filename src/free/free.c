/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 04:34:50 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/30 14:29:12 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear_m(t_arg **lst)
{
	t_arg	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		(*lst)->type = 0;
		if ((*lst)->value)
		{
			(*lst)->value = NULL;
			free ((*lst)->value);
		}
		free ((*lst));
		*lst = tmp;
	}
	*lst = NULL;
}