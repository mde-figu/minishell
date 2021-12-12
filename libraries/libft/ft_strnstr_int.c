/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:41:02 by mde-figu          #+#    #+#             */
/*   Updated: 2021/12/12 17:41:05 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr_indie(const char *big, const char *small, size_t len)
{
	size_t	needle_len;
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)big;
	needle_len = ft_strlen(small);
	if (!needle_len)
		return (0);
	while (*tmp && len >= needle_len)
	{
		if (ft_strncmp(tmp, small, needle_len) == 0)
			return (i + needle_len);
		tmp++;
		i++;
	}
	return (INT_MAX);
}
