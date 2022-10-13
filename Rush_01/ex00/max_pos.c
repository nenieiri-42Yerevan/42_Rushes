/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:45:58 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/13 17:19:10 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	*max_pos(int *str, int size)
{
	int	i;
	int	*val;

	i = -1;
	val = str;
	while (++i < size)
	{
		if (str[i] > *val)
			val = str + i;
	}
	return (val);
}
