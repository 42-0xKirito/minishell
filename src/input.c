/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:40:35 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/30 16:28:15 by engiacom         ###   ########.fr       */
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
		if (*line != '\0')
			add_history(line);
		if (!check_quote(line))
		{
			parser(line, &data->arg);
			if (!check_pipe(data->arg))
			{
				print(data->arg);
				free(line);
			}
			else
				printf("rl_on_new_line\n");
			ft_lstclear_m(&data->arg);
		}
		else
				printf("rl_on_new_line\n");
	}
	return (0);
}