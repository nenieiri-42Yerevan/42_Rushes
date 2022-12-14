/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:02:54 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/17 14:33:26 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	line_count_up(int **map_matrix, int j, int size)
{
	int	k;
	int	count;
	int	height;

	count = 0;
	height = 0;
	k = -1;
	while (++k != size)
	{
		if (map_matrix[k][j] > height)
		{
			height = map_matrix[k][j];
			++count;
		}
	}
	return (count);
}

static int	line_count_down(int **map_matrix, int j, int size)
{
	int	k;
	int	count;
	int	height;

	count = 0;
	height = 0;
	k = size;
	while (--k != -1)
	{
		if (map_matrix[k][j] > height)
		{
			height = map_matrix[k][j];
			++count;
		}
	}
	return (count);
}

static int	line_count_left(int **map_matrix, int i, int size)
{
	int	k;
	int	count;
	int	height;

	count = 0;
	height = 0;
	k = -1;
	while (++k != size)
	{
		if (map_matrix[i][k] > height)
		{
			height = map_matrix[i][k];
			++count;
		}
	}
	return (count);
}

static int	line_count_right(int **map_matrix, int i, int size)
{
	int	k;
	int	count;
	int	height;

	count = 0;
	height = 0;
	k = size;
	while (--k != -1)
	{
		if (map_matrix[i][k] > height)
		{
			height = map_matrix[i][k];
			++count;
		}
	}
	return (count);
}

int	check_map(t_matrix *matrixes, int size)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	if (check_dublicates(matrixes->map_matrix, size) == 0)
		return (0);
	while (++i < 4)
	{
		j = -1;
		while (matrixes->input_matrix[i][++j] != '\0')
		{
			if (i == 0)
				count = line_count_up(matrixes->map_matrix, j, size);
			else if (i == 1)
				count = line_count_down(matrixes->map_matrix, j, size);
			else if (i == 2)
				count = line_count_left(matrixes->map_matrix, j, size);
			else if (i == 3)
				count = line_count_right(matrixes->map_matrix, j, size);
			if (matrixes->input_matrix[i][j] != count)
				return (0);
		}
	}
	return (1);
}
