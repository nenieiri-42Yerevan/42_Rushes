/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:19:01 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/11 15:19:01 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

void	fill_map_matrix(int **map_matrix, int size)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (map_matrix[++i] != 0)
	{
		k = i + 1;
		j = -1;
		while (++j < size)
		{
			map_matrix[i][j] = k;
			++k;
			if (k > size)
				k = 1;
		}
	}
}
