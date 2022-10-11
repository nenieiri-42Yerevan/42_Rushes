/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:19:01 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/11 13:21:44 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

static void	fill_map_matrix(char **map_matrix, int size)
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

char	**create_map_matrix(int size)
{
	char	**map_matrix;
	int		i;

	i = -1;
	map_matrix = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map_matrix)
		return (0);
	map_matrix[size] = 0;
	while (map_matrix[++i] != 0)
	{
		map_matrix[i] = (char *)malloc(sizeof(int) * (size + 1));
		if (!map_matrix)
		{
			free_matrix(map_matrix, i);
			return (0);
		}
		map_matrix[i][size] = 0;
	}
	fill_map_matrix(map_matrix, size);
	return (map_matrix);
}
