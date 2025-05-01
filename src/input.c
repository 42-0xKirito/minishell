/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:45:35 by nitadros          #+#    #+#             */
/*   Updated: 2025/05/01 18:29:34 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void    print(t_arg *arg)
// {
//     while (arg)
//     {
//         printf("%s\n", arg->value);
//         arg = arg->next;
//     }
// 	printf("\n");
// }
int	read_input(t_data *data)
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		if (*line != '\0')
			add_history(line);
		if (!check_quote(line))
		{
			parser(line, &data->arg);
			if (!check_pipe(data->arg))
			{
				expanser(&data->arg);
				reassembler(data);
			}
			else
				printf("rl_on_new_line\n");
		}
		else
		{
			printf("rl_on_new_line\n");
		}
		free(line);
		ft_lstclear_m(&data->arg);
		ft_lstclear_c(&data->cmd);
	}
	return (0);
}
