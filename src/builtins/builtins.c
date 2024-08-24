/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   builtins.c                                        :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/08/04 18:46:29 by sreerink      #+#    #+#                 */
/*   Updated: 2024/08/24 21:21:57 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	execute_builtin(t_cmd *cmd, t_data *data)
{
	int		exit_status;

	if (cmd->builtin == CD)
		exit_status = cd_builtin(cmd, data);
	else if (cmd->builtin == ECHO)
		exit_status = echo_builtin(cmd);
	else if (cmd->builtin == PWD)
		exit_status = pwd_builtin();
	return (exit_status);
}
