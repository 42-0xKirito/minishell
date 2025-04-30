/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:22:24 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/30 05:14:32 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

typedef enum e_token_type
{
	T_WORD,
	T_SPACE,
	T_PIPE,
	T_R_IN, // <
	T_R_OUT, // >
	T_HEREDOC, // <<
	T_APPEND, // >>
	T_QUOTE,
	T_DQUOTE,
	T_VAR,
	T_UNKNOWN
}	t_token_type;



typedef struct s_arg
{
	t_token_type	type;
	char			*value;
	struct s_arg	*next;
	
}	t_arg;

typedef struct s_data
{
	t_arg	*arg;
}	t_data;

// SRC
int	read_input();
int	main(int ac, char **av, char **env);

// PARSER
int	parser(char *line, t_arg **arg);

// EXEC
//int	echo(char **arg);
// int	is_builtin(const char *cmd);
// int	exec_builtin(char **args);

// UTILS
t_arg	*ft_lstnew_m(t_token_type type, char *value);
void	ft_lstadd_back_m(t_arg **arg, t_arg *new);
int		is_separator(char c);