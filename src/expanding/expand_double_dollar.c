/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_double_dollar.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/04 15:27:10 by diwalaku      #+#    #+#                 */
/*   Updated: 2024/07/04 15:27:10 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// bool	is_double_dollar(t_node *node, t_expand *info, bool is_expandable)
// {
// 	int	i;

// 	i = 0;
// 	if (is_expandable == false || (node->type != WORD && \
// 		node->type != DOUBLE_QUOTE))
// 		return (false);
// 	while (node->str[i])
// 	{
// 		if (node->str[i] == '$' && node->str[i + 1] == '$')
// 			return (true);
// 		i++;
// 	}
// 	return (false);
// }


// void	set_pid(t_node *node, t_expand *info)
// {
// 	t_node	*new;
// 	char	*pid;
// 	int		i;

// 	i = 0;
// 	pid = ft_itoa(getpid());
// 	while (i < info->strlen)
// 	{
// 		if (node->str[i] == '$' && node->str[i + 1] == '$')
// 		{
// 			new = create_node()
// 		}
// 	}
// }
