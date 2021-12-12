/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:47:20 by mde-figu          #+#    #+#             */
/*   Updated: 2021/12/12 17:47:21 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_all(t_array_table *table)
{
	int				i;
	t_ht_item		*item;

	i = 0;
	if (table != NULL)
	{
		if (table->item)
		{
			while (i < table->size)
			{
				item = table->item[i];
				if (item)
					free_item(item);
				i++;
			}
			free(table->item);
		}
		free(table);
	}
}

void	free_n_exit(void)
{
	free_all(g_shell.env);
	free_all(g_shell.local);
	exit(errno);
}

void	free_item(t_ht_item *item)
{
	if (item->key)
		free(item->key);
	if (item->value)
		free(item->value);
	free(item);
}
