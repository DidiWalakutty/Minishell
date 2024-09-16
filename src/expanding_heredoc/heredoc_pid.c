/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc_pid.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: didi <didi@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/11 17:00:49 by didi          #+#    #+#                 */
/*   Updated: 2024/09/16 20:54:58 by didi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_heredoc_double(char *str, int i)
{
	if (str[i] == '$')
	{
		if (str[i + 1] == '{')
		{
			i += 2;
			if (str[i] == '$')
				return (true);
			return (false);
		}
		if (str[i + 1] == '$')
			return (true);
	}
	return (false);
}

t_h_dol	*init_here_pid(char *str)
{
	t_h_dol	*new;

	new = mem_check(malloc(sizeof(t_h_dol)));
	new->expanded = NULL;
	new->env_name = ft_itoa(getpid());
	new->copy = ft_strdup(str);
	new->i = 0;
	new->str_len = ft_strlen(str);
	new->start_env = 0;
	new->end_var = 0;
	new->brackets = false;
	new->no_closing_brackets = false;
	new->exp_kind = IS_PID;
	return (new);
}

void	expand_heredoc_pid(char *str, int *i, t_h_dol *info, char **env)
{
	int	j;

	j = *i + 1;
	if (str[j] == '{')
		j++;
	info->start_env = j;
	info->end_var = j;
	if (str[j + 1] && (str[j + 1] == '$'))
	{
		if (info->brackets == true)
			printf("theres brackets\n");
			// ended here
	}
}
