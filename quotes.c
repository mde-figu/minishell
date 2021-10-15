/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:28:08 by mde-figu          #+#    #+#             */
/*   Updated: 2021/10/15 00:53:52 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	quote_commander(char **cmd)
{
	int j;
	int k;

	j = 0;
	while (cmd[0][j])
	{
		if (cmd[0][j] == '\"' || cmd[0][j] == '\'')
		{
			k = j + 1;
			while (cmd[0][k])
			{
				if (cmd[0][k] == cmd[0][j]) 
				{
					cmd[0][j] = ' ';
					cmd[0][k] = ' ';
					break;
				}
				k++;
			}
			j = k - 1;
		}
		j++;
	}
}
