/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                            :+:    :+:             */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/14 18:40:07 by diwalaku      #+#    #+#                 */
/*   Updated: 2024/07/26 19:03:26 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// isatty checks if the standard input is pointing to our terminal,
// still needs to have a quit_program function.
// Copies env, unsets old PWD and increments shlvl.
// Sets all variables to NULL.
// Termcaps???
// process al op 1 ivm child

void	error_exit(const char *msg, int status)
{
	if (msg)
		perror(msg);
	exit(status);
}

static t_data	*init_shell(char **env)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	// if (!isatty(STDIN_FILENO))
	// 	exit_program();
	data->env = copy_env(env);
	data->input = NULL;
	data->list = NULL;
	data->process = 1;
	// data->token = NULL; Not needed?
	// TODO: PATH's
	// TODO: unset old PWD
	// TODO: increment shlvl
	// signals
	return (data);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	char	*input;
	int		i;
	t_cmd	*current;

	(void)argc;
	(void)argv;
	data = init_shell(env);
	while (1)
	{
		data->input = NULL;
		data->list = NULL;
		data->process = 1;
		input = readline(SHELL_NAME);
		if (!input)
			error_exit("readline", EXIT_FAILURE);
		data->input = input;
		if (input != NULL)
			add_history(data->input);
		// printf("In main before expanding:\n");
		lexer_and_parser(data);
		// print_linked_list(data->list);
		data->cmd_process = make_cmd_nodes(data);
		current = data->cmd_process;
		printf("After make_cmd_nodes():\n");
		while (current)
		{
			i = 0;
			while (current->args && current->args[i])
			{
				printf("%s\n", current->args[i]);
				i++;
			}
			current = current->next;
		}
		//make_processes(data);
		// free_all(data);
	}
	return (0);
}
