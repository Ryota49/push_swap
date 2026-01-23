/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:18:22 by jemonthi          #+#    #+#             */
/*   Updated: 2025/12/17 22:58:50 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *digits)
{
	int		x;
	long	result;
	int		sign;

	if (ft_strlen(digits) > 11)
	{
		result = 184467440737;
		return (result);
	}
	sign = 1;
	x = 0;
	result = 0;
	if (digits[x] == '+' || digits[x] == '-')
	{
		if (digits[x] == '-')
			sign = -1;
		x++;
	}
	while (digits[x] >= '0' && digits[x] <= '9')
	{
		result = result * 10 + digits[x] - '0';
		x++;
	}
	return (result * sign);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	*sub_string(char const *s, char *li_s, unsigned int st, size_t l)
{
	size_t	i;

	i = 0;
	while (s[st] && i < l)
	{
		li_s[i] = s[st];
		st++;
		i++;
	}
	li_s[i] = '\0';
	return (li_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*little_s;

	if (!s)
		return (NULL);
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	if (s == 0 || start > ft_strlen((char *)s))
	{
		little_s = malloc(sizeof(char));
		if (!little_s)
			return (NULL);
		little_s[0] = '\0';
		return (little_s);
	}
	little_s = malloc(sizeof(char) * len + 1);
	if (!little_s)
		return (NULL);
	little_s = sub_string(s, little_s, start, len);
	return (little_s);
}
