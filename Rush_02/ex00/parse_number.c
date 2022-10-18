/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:31:42 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/18 12:52:30 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*parse_number(char *str)
{
	char	*res;
	int		is_neg;

	is_neg = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	while (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			is_neg *= -1;
	}
	if (is_neg == -1 || *str == 0)
		return (0);
	while (*str == '0' && *(str + 1) != 0)
		++str;
	res = str;
	while (*str != 0 && *str >= '0' && *str <= '9')
		++str;
	if (*str == 0)
		return (res);
	return (0);
}
