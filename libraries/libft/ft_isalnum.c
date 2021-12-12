/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:32:14 by mde-figu          #+#    #+#             */
/*   Updated: 2021/12/12 17:32:17 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	ret;

	ret = 1;
	if ((c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
	{
		ret = 1;
	}
	else if (c >= 48 && c <= 57)
	{
		ret = 1;
	}
	else
	{
		ret = 0;
	}
	return (ret);
}
