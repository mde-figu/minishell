/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_by_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:18:04 by nbarreir          #+#    #+#             */
/*   Updated: 2021/10/15 22:15:00 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*search_hash_by_key(char *key)
{
	int	c;

	c = 0;
	while(g_shell.env->items[c] && c <= g_shell.env->size - 1)
	{
		if (ft_strncmp(g_shell.env->items[c]->key, key, ft_strlen(key)) == 0)
			return(g_shell.env->items[c]->value);
		c++;
	}
	c = 0;
	while(g_shell.hash->items[c] && c <= g_shell.hash->size - 1)
	{
		if (ft_strncmp(g_shell.hash->items[c]->key, key, ft_strlen(key)) == 0)
			return(g_shell.hash->items[c]->value);
		c++;
	}
	while(g_shell.temp->items[c] && c <= g_shell.temp->size - 1)
	{
		if (ft_strncmp(g_shell.temp->items[c]->key, key, ft_strlen(key)) == 0)
			return(g_shell.temp->items[c]->value);
		c++;
	}
	return (NULL);
}

void	modify_hash_by_key(char *key, char *new_val)
{
	int	c;

	c = 0;
	while(g_shell.env->items[c] && c <= g_shell.env->size - 1)
	{
		if (ft_strncmp(g_shell.env->items[c]->key, key, ft_strlen(key)) == 0)
		{
			free_item(g_shell.env->items[c]);
				g_shell.env->items[c] = insert_table(key, new_val);
			return ;
		}
		c++;
	}
	c = 0;
	while(g_shell.hash->items[c] && c <= g_shell.hash->size - 1)
	{
		if (ft_strncmp(g_shell.hash->items[c]->key, key, ft_strlen(key)) == 0)
		{
			free_item(g_shell.hash->items[c]);
				g_shell.hash->items[c] = insert_table(key, new_val);
			return ;
		}
		c++;
	}
	c = 0;
	while(g_shell.temp->items[c] && c <= g_shell.temp->size - 1)
	{
		if (ft_strncmp(g_shell.temp->items[c]->key, key, ft_strlen(key)) == 0)
		{
			free_item(g_shell.temp->items[c]);
				g_shell.temp->items[c] = insert_table(key, new_val);
			return ;
		}
		c++;
	}
}