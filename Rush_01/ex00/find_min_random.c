/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_random.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:23:51 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/16 16:10:47 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	if_end(t_matrix *matrixes, int size)
{
	int	row;
	int	col;

	row = -1;
	while (++row < size)
	{
		col = -1;
		while (++col < size)
			if (matrixes->helper_matrix[row][col] != 0)
				return (1);
	}
	return (-1);
}

static int	count_size(int *helper_matrix, int size)
{
	int	count;
	int	j;

	count = 0;
	j = -1;
	while (++j < size)
	{
		if (helper_matrix[j] != -10)
			++count;
	}
	return (count);
}

static int	*find_cell(t_matrix *matrixes, int size, int count)
{
	int	row;
	int	col;
	int	*cell;

	row = -1;
	cell = (int *)malloc(sizeof(int) * 2);
	if (!cell)
		return (0);
	while (matrixes->helper_matrix[++row] != 0)
	{
		col = -1;
		while (++col < size)
		{
			if (matrixes->helper_matrix[row][col] == 0)
				continue ;
			if (count_size(matrixes->helper_matrix[row][col], size) == count)
			{
				cell[0] = row;
				cell[1] = col;
				return (cell);
			}
		}
	}
	return (0);
}

static int	*no_solution(int **cell)
{
	*cell = (int *)malloc(sizeof(int) * 2);
	if (!(*cell))
		return (0);
	(*cell)[0] = -1;
	(*cell)[1] = -1;
	return (*cell);
}

int	*find_min_random(t_matrix *matrixes, int size)
{
	int	count;
	int	row;
	int	col;
	int	*cell;

	count = 10;
	cell = 0;
	if (if_end(matrixes, size) == -1)
		return (no_solution(&cell));
	row = -1;
	while (matrixes->helper_matrix[++row] != 0)
	{
		col = -1;
		while (++col < size)
		{
			if (matrixes->helper_matrix[row][col] == 0)
				continue ;
			if (count_size(matrixes->helper_matrix[row][col], size) < count)
				count = count_size(matrixes->helper_matrix[row][col], size);
		}
	}
	return (find_cell(matrixes, size, count));
}
