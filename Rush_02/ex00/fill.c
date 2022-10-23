/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:42:42 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/23 11:47:18 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*fill(char *dest, char *number)
{
	int j;
	int i;

	i = 0;
	while (dest[i])
		i++;
	j = -1;
	while (number[++j])
		dest[i + j] = number[j];
	dest[i + j] = '\0';
	return (dest);
}
