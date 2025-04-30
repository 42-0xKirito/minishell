/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:40:35 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/30 05:00:03 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print(t_arg *arg)
{
	while (arg)
	{
		printf("%s\n", arg->value);
		arg = arg->next;
	}
}

int	read_input(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break;
		parser(line, &data->arg);
		print(data->arg);
		if (*line != '\0')
			add_history(line);
		free(line);
	}
	return (0);
}