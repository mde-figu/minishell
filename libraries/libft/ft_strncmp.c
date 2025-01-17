/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:40:54 by mde-figu          #+#    #+#             */
/*   Updated: 2021/12/12 17:40:56 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c;
	unsigned char	d;

	if (n == 0)
		return (0);
	n = n - 1;
	while (n--)
	{
		c = (unsigned char)*s1;
		s1 = s1 + 1;
		d = (unsigned char)*s2;
		s2 = s2 + 1;
		if (c == '\0' || c != d)
			return (c - d);
	}
	c = (unsigned char)*s1;
	s1 = s1 + 1;
	d = (unsigned char)*s2;
	s2 = s2 + 1;
	return (c - d);
}
