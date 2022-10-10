/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:50:08 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/10 18:18:09 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

static void	fix(char **map_matrix, int i, int j, int size)
{
	if (--j < 0)
	{
		j = size - 1;
		if (--i < 0)
			return ;
	}
	while (map_matrix[i][j] == size)
	{
		map_matrix[i][j] -= 1;
		if (--j < 0)
		{
			j = size;
			if (--i < 0)
				return ;
		}
	}
}

void	change_matrix(char **map_matrix, int size)
{
	int	i;
	int	j;

	i = -1;
	while (map_matrix[++i] != 0)
	{
		j = -1;
		while (map_matrix[++j] != 0)
		{
			if (map_matrix[i][j] == size && i == size && j == size)
				return ;
			else if (map_matrix[i][j] < size)
			{
				map_matrix[i][j] += 1;
				fix(map_matrix, i, j, size);
				return ;
			}
		}
	}
}
