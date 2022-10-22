/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:35:58 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/22 12:45:42 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*format_string(char *number)
{
	int		zeroes_to_add;
	char	*formatted_string;
	int		i;

	i = -1;
	zeroes_to_add = (3 - ft_strlen(number) % 3) % 3;
	formatted_string = 0;
	formatted_string = (char *)malloc(sizeof(char) * \
									(ft_strlen(number) + zeroes_to_add + 1));
	if (!formatted_string)
		return (0);
	while (zeroes_to_add--)
		formatted_string[++i] = '0';
	formatted_string[++i] = '\0';
	return (fill(formatted_string, number));
}
