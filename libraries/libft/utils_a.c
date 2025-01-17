/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:43:25 by mde-figu          #+#    #+#             */
/*   Updated: 2021/12/12 17:43:27 by mde-figu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_putnbr(long int c, char *str, long int i)
{
	long unsigned	m;

	m = c;
	if (c < 0)
	{
		str[0] = '-';
		m = (m * (-1));
	}
	if (m >= 10)
		convert_putnbr((m / 10), str, (i - 1));
	str[i] = (m % 10) + '0';
}

char	*ft_itoa_f(long int n)
{
	char		*str;
	long int	j;
	long int	count;

	j = n;
	count = 0;
	if (j <= 0)
		count++;
	while (j)
	{
		j = (j / 10);
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = 0;
	convert_putnbr(n, str, (count - 1));
	return (str);
}

char	*utoa(unsigned int n)
{
	unsigned int	count;
	unsigned int	num;
	char			*temp;

	count = 1;
	num = n;
	while (n >= 10 && count++)
		n /= 10;
	temp = malloc((count + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	*(temp + count) = '\0';
	while (count--)
	{
		*(temp + count) = num % 10 + '0';
		num /= 10;
	}
	return (temp);
}

/*
** Converts input into hexadecimal x and X
*/

static char	*hextoa_a(char *str, t_flags *flags, unsigned long long temp,
					int count)
{
	while (temp != 0)
	{
		if ((flags->type == 'x' || flags->type == 'p') && (temp % 16) >= 10)
			str[count - 1] = (temp % 16) + 87;
		else if (flags->type == 'X' && (temp % 16) >= 10)
			str[count - 1] = (temp % 16) + 55;
		else
			str[count - 1] = (temp % 16) + 48;
		temp = temp / 16;
		count--;
	}
	return (str);
}

char	*hextoa(t_flags *flags, unsigned long long nb)
{
	int					count;
	char				*str;
	unsigned long long	temp;

	temp = nb;
	count = 0;
	if (nb == 0)
		return (ft_strdup_f("0"));
	while (nb != 0)
	{
		nb = nb / 16;
		count++;
	}
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	str = hextoa_a(str, flags, temp, count);
	return (str);
}
