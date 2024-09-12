/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_commands.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/22 18:14:06 by diwalaku      #+#    #+#                 */
/*   Updated: 2024/09/12 17:59:12 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_command_and_args(t_token **token, t_cmd **curr_cmd)
{
	if ((*curr_cmd)->cmd == NULL)
	{
		if ((*token)->type == WORD || (*token)->type == SINGLE_QUOTE || \
			(*token)->type == DOUBLE_QUOTE)
		{
			(*curr_cmd)->cmd = ft_strdup((*token)->str);
			(*curr_cmd)->args = add_to_double_array((*curr_cmd)->args, \
								(*token)->str);
		}
	}
	else
	{
		if ((*token)->type == PIPE)
		{
			(*curr_cmd)->pipe_out = true;
			(*curr_cmd)->next = init_cmds();
			(*curr_cmd) = (*curr_cmd)->next;
			(*curr_cmd)->pipe_in = true;
		}
		else
			(*curr_cmd)->args = add_to_double_array((*curr_cmd)->args, \
								(*token)->str);
	}
}

t_cmd	*merge_commands(t_token *tokens, t_data *data)
{
	t_cmd	*command_list;
	t_cmd	*current_cmd;

	command_list = init_cmds();
	current_cmd = command_list;
	init_redirects(current_cmd);
	while (tokens)
	{
		if (a_redirection(tokens->type) == true)
		{
			if (handle_redirect(&tokens, &current_cmd) != 1)
				printf("check for failure and free");
		}
		else
			set_command_and_args(&tokens, &current_cmd);
		tokens = tokens->next;
	}
	return (command_list);
}

t_cmd	*build_commands(t_token *tokens, t_data *data)
{
	t_cmd		*commands;

	commands = NULL;
	if (tokens && not_just_spaces(tokens) && empty_words(tokens))
	{
		commands = merge_commands(tokens, data);
		commands->env = data->env;
	}
	return (commands);
}
