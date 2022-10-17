/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dublicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:17:34 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/17 14:30:21 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	check_in_col(int **map_matrix, int row, int col, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (i == row)
			continue ;
		if (map_matrix[i][col] == map_matrix[row][col])
			return (0);
	}
	return (1);
}

static int	check_in_row(int **map_matrix, int row, int col, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (i == col)
			continue ;
		if (map_matrix[row][i] == map_matrix[row][col])
			return (0);
	}
	return (1);
}

int	check_dublicates(int **map_matrix, int size)
{
	int	row;
	int	col;

	row = -1;
	while (++row < size)
	{
		col = -1;
		while (++col < size)
		{
			if (check_in_row(map_matrix, row, col, size) == 0)
				return (0);
			if (check_in_col(map_matrix, row, col, size) == 0)
				return (0);
		}
	}
	return (1);
}
