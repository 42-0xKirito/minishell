/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:57:12 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/30 17:12:06 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_var_word(char *c, int i, t_arg **arg)
{
	int		k;
	char	*s;

	k = 0;
	if (c[i] && c[i] == '$')
	{
		ft_lstadd_back_m(arg, ft_lstnew_m(T_VAR, "$"));
		return (1);
	}
	while (c[i + k] && !(is_separator(c[i + k])))
		k++;
	if (k > 0)
	{
		s = ft_substr(c, i, k);
		ft_lstadd_back_m(arg, ft_lstnew_m(T_WORD, s));
		return (k);
	}
	return (0);
}

int	token_other(char *c, int i, t_arg **arg)
{
	int		k;
	char	*s;

	//s = NULL;
	k = 0;
	if (c[i] && c[i] == ' ')
	{
		ft_lstadd_back_m(arg, ft_lstnew_m(T_SPACE, " "));
		return (1);
	}
	else if (c[i] && c[i] == '|')
	{
		ft_lstadd_back_m(arg, ft_lstnew_m(T_PIPE, "|"));
		return (1);
	}
	else if (c[i] && c[i] == '\'')
	{
		k++;
		while (c[i + k] && c[i + k] != '\'')
			k++;
		if (c[i + k] == '\'')
			k++;
		s = ft_substr(c, i, k);
		ft_lstadd_back_m(arg, ft_lstnew_m(T_QUOTE, s));
		free(s);
		return (k);
	}
	else if (c[i] && c[i] == '\"')
	{
		k = 1;
		while (c[i + k] && c[i + k] != '\"')
			k++;
		if (c[i + k] == '\"')
			k++;
		s = ft_substr(c, i, k);
		printf("str = %s\n", s);
		ft_lstadd_back_m(arg, ft_lstnew_m(T_DQUOTE, s));
		free(s);
		return (k);
	}
	return (0);
}

int	token_r_right(char *c, int i, t_arg **arg)
{
	if (c[i] && c[i] == '>')
	{
		if (c[i + 1] && c[i + 1] == '>')
		{
			ft_lstadd_back_m(arg, ft_lstnew_m(T_APPEND, ">>"));
			return (2);
		}
		else
		{
			ft_lstadd_back_m(arg, ft_lstnew_m(T_R_OUT, ">"));
			return (1);
		}
	}
	return (0);
}

int	token_r_left(char *c, int i, t_arg **arg)
{
	if (c[i] && c[i] == '<')
	{
		if (c[i + 1] && c[i + 1] == '<')
		{
			ft_lstadd_back_m(arg, ft_lstnew_m(T_HEREDOC, "<<"));
			return (2);
		}
		else
		{
			ft_lstadd_back_m(arg, ft_lstnew_m(T_R_IN, "<"));
			return (1);
		}
	}
	return (0);
}

int	parser(char *line, t_arg **arg)
{
	int	i;

	i = 0;
	while (line[i])
	{
			i += token_r_left(line, i, arg);
			i += token_r_right(line, i, arg);
			i += token_other(line, i, arg);
			i += token_var_word(line, i, arg);
	}
	return (0);
}
