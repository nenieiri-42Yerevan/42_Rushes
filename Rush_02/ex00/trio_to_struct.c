/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trio_to_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:28:56 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/23 11:48:55 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static char	*strndup_buff(char *str, int n, int buffer_extension)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (n + 1 + buffer_extension));
	if (dest == NULL)
		return (0);
	i = -1;
	while (++i < n)
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}

t_trio	*trio_to_struct(char *str)
{
	t_trio *result;
	char	*tmp;

	result = (t_trio *)malloc(sizeof(t_trio));
	if (!result)
		return (0);
	result->hundred = 0;
	result->hundred_units = 0;
	result->dozen = 0;
	result->unit = 0;
	if (str[0] >= '1')
	{
		result->hundred_units = strndup_buff(&str[0], 1, 0);
		result->hundred = strndup_buff("100", 3, 0);
	}
	if (str[1] >= '2')
	{
		tmp = strndup_buff("0", 1, 0);
		result->dozen = fill(strndup_buff(&str[1], 1, 1), tmp);
		free(tmp);
	}
	if (str[1] == '1')
	{
		tmp = strndup_buff(&str[2], 1, 0);
		result->unit = fill(strndup_buff("1", 1, 1), tmp);
		free(tmp);
	}
	else if (str[2] != '0')
		result->unit = strndup_buff(&str[2], 1, 0);
	return (result);
}
