/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:34:01 by mde-figu          #+#    #+#             */
/*   Updated: 2021/12/12 17:34:04 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counter(int n)
{
	if (!(n / 10))
		return (1);
	else
		return (counter(n / 10) + 1);
}

char	*ft_itoa(int n)
{
	unsigned int	integer;
	size_t			len;
	char			*str;

	len = counter(n);
	if (n < 0)
	{
		integer = -(unsigned int)n;
		len++;
	}
	else
		integer = (unsigned int)n;
	str = malloc((len + 1) * sizeof(*str));
	if (!(str))
		return (0);
	str[len] = '\0';
	while (len--)
	{
		str[len] = integer % 10 + '0';
		integer = integer / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
