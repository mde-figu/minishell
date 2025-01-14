/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_by_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:47:03 by mde-figu          #+#    #+#             */
/*   Updated: 2021/12/12 17:47:05 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*search_array_by_key(char *key)
{
	int	c;

	c = 0;
	while (g_shell.env->item[c] && c <= g_shell.env->size - 1)
	{
		if (ft_strncmp(g_shell.env->item[c]->key, key, ft_strlen(key)) == 0)
			return (g_shell.env->item[c]->value);
		c++;
	}
	c = 0;
	while (g_shell.local->item[c] && c <= g_shell.local->size - 1)
	{
		if (ft_strncmp(g_shell.local->item[c]->key, key, ft_strlen(key)) == 0)
			return (g_shell.local->item[c]->value);
		c++;
	}
	return (NULL);
}

void	modify_array_by_key(char *key, char *new_val)
{
	int	c;

	c = 0;
	while (g_shell.env->item[c] && c <= g_shell.env->size - 1)
	{
		if (ft_strncmp(g_shell.env->item[c]->key, key, ft_strlen(key)) == 0)
		{
			free_item(g_shell.env->item[c]);
			g_shell.env->item[c] = insert_table(key, new_val);
			return ;
		}
		c++;
	}
	c = 0;
	while (g_shell.local->item[c] && c <= g_shell.local->size - 1)
	{
		if (ft_strncmp(g_shell.local->item[c]->key, key, ft_strlen(key)) == 0)
		{
			free_item(g_shell.local->item[c]);
			g_shell.local->item[c] = insert_table(key, new_val);
			return ;
		}
		c++;
	}
}

void	insert_or_modify_by_key(char *key, char *new_val)
{
	if (search_array_by_key(key))
		modify_array_by_key(key, new_val);
	else
		loop_table_n_insert(key, new_val, ENV);
}
