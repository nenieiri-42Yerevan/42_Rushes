/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:52:45 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/18 16:22:50 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strchr(const char *s, int c)
{
	char	*new_s;

	new_s = (char *)s;
	while (*new_s != '\0')
	{
		if (*new_s == c)
			return (new_s);
		new_s++;
	}
	if (*new_s == '\0' && c == '\0')
		return (new_s);
	return (0);
}
