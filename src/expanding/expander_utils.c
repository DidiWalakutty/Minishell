/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/04 15:35:01 by diwalaku      #+#    #+#                 */
/*   Updated: 2024/09/10 14:48:56 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_heredoc(t_token *node)
{
	int	i;

	i = 0;
	if (node->type != HERE_DOC)
		return (false);
	while (node->str[i])
	{
		if (node->str[i] == '<' && node->str[i + 1] == '<')
			return (true);
		i++;
	}
	return (false);
}

static char	*check_joined(char *before, char *fill_in)
{
	char	*replacement;

	replacement = NULL;
	if (before && before[0] != '\0')
		replacement = ft_strconcat(before, fill_in);
	else
		replacement = ft_strdup(fill_in);
	return (replacement);
}

// 	free(dol->expanded); ???
// Can't free(joined), because it's now owned by ceate_node;
// It would deallocate the memory while the node still needs to use it.
//
// Expand nodes checks and concatenates before expansion, 
// the expansion and the possible remainder, 
// creates a node and adds it to the list.
void	expand_node(t_token *node, t_dollar *dol)
{
	char	*before;
	char	*remainder;
	char	*joined;

	if (!node->str)
		return ;
	joined = NULL;
	before = ft_substr(node->str, 0, dol->i);
	remainder = ft_substr(node->str, dol->end_var, dol->str_len);
	if (before && before[0] != '\0')
		joined = ft_strdup(before);
	if (dol->expanded && dol->expanded[0] != '\0')
		joined = check_joined(joined, dol->expanded);
	if (remainder && remainder[0] != '\0')
		joined = check_joined(joined, remainder);
	if (!joined)
		joined = ft_strdup("");
	free(node->str);
	node->str = joined;
	free(before);
	free(remainder);
}

// Compares each line of env with the given string, like
// pwd, user etc.
char	*copy_env_input(char **env, char *to_find)
{
	int		i;
	int		find_len;
	char	*result;

	i = 0;
	find_len = ft_strlen(to_find);
	while (env[i])
	{
		if (env[i][find_len] == '=' && \
			ft_strncmp(env[i], to_find, find_len) == 0)
		{
			result = ft_strdup(env[i] + find_len + 1);
			return (result);
		}
		i++;
	}
	return (NULL);
}
