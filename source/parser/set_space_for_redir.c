/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_space_for_redir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:45:34 by mde-figu          #+#    #+#             */
/*   Updated: 2021/12/12 17:45:35 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*put_space_before(char *cmd, int i)
{
	char	*ret;
	int		j;

	ret = ft_calloc(ft_strlen(cmd) + 1, sizeof(char *));
	if (ret == NULL)
	{
		perror("Error: ");
		free(cmd);
		return (NULL);
	}
	j = 0;
	while (j < i)
	{
		ret[j] = cmd[j];
		j++;
	}
	ret[j++] = ' ';
	while (cmd[i] != '\0')
		ret[j++] = cmd[i++];
	free(cmd);
	return (ret);
}

char	*put_space_after(char *cmd, int i)
{
	char	*ret;
	int		j;

	ret = ft_calloc(ft_strlen(cmd) + 1, sizeof(char *));
	if (ret == NULL)
	{
		perror("Error: ");
		free(cmd);
		return (NULL);
	}
	j = 0;
	while (j <= i)
	{
		ret[j] = cmd[j];
		j++;
	}
	ret[j++] = ' ';
	while (cmd[i] != '\0')
		ret[j++] = cmd[++i];
	free(cmd);
	return (ret);
}

char	*set_space_for_redir(char *cmd, int *i)
{
	int	j;

	if (*i != 0)
	{
		if (cmd[*i - 1] != ' ')
		{
			j = *i;
			cmd = put_space_before(cmd, j);
			if (cmd == NULL)
				return (NULL);
			(*i)++;
		}
	}
	if (cmd[*i] == cmd[*i + 1])
		(*i)++;
	if (cmd[*i + 1] != '\0' && cmd[*i + 1] != ' ')
	{
		j = *i;
		cmd = put_space_after(cmd, j);
		if (cmd == NULL)
			return (NULL);
	}
	return (cmd);
}
