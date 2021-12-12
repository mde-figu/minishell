/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:41:11 by mde-figu          #+#    #+#             */
/*   Updated: 2021/12/12 17:41:13 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(small);
	if (!needle_len)
		return ((char *)big);
	while (*big && len >= needle_len)
	{
		if (!ft_strncmp(big, small, needle_len))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
