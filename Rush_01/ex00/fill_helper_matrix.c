/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_helper_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:52:33 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/11 17:31:12 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

static void	fill_0(int **helper_matrix, int size)
{
	int	i;
	int	j;

	i = -1;
	while (helper_matrix[++i] != 0)
	{
		j = -1;
		while (helper_matrix[i][++j] != 0)
			helper_matrix[i][j] = size;
	}
}

static int	optimizer_up(int **map_matrix, int **input_matrix, \
							int **helper_matrix, int size)
{
	int	j;
	int	k;

	j = -1;
	while (input_matrix[0][++j] != 0)
	{
		k = -1;
		if (input_matrix[0][j] == 1)
		{
			if (helper_matrix[0][j] == -1 && map_matrix[0][j] != size)
				return (-1);
			helper_matrix[0][j] = -1;
			map_matrix[0][j] = size;
		}
		else if (input_matrix[0][j] == size)
		{
			while (map_matrix[++k] != 0)
			{
				if (helper_matrix[k][j] == -1 && map_matrix[k][j] != k + 1)
					return (-1);
				map_matrix[k][j] = k + 1;
				helper_matrix[k][j] = -1;
			}
		}
		else
		{
			if (helper_matrix[0][j] == -1 && map_matrix[0][j] > size - \
					input_matrix[0][j] + 1)
				return (-1);
			helper_matrix[0][j] = size - input_matrix[0][j] + 1;
		}
	}
	return (0);
}

static int	optimizer_down(int **map_matrix, int **input_matrix, \
							int **helper_matrix, int size)
{
	int	j;
	int	k;

	j = -1;
	while (input_matrix[1][++j] != 0)
	{
		k = -1;
		if (input_matrix[1][j] == 1)
		{
			if (helper_matrix[size - 1][j] == -1 && map_matrix[size - 1][j] != size)
				return (-1);
			helper_matrix[size - 1][j] = -1;
			map_matrix[size - 1][j] = size;
		}
		else if (input_matrix[1][j] == size)
		{
			while (map_matrix[++k] != 0)
			{
				if (helper_matrix[k][j] == -1 && map_matrix[k][j] != size - k)
					return (-1);
				map_matrix[k][j] = size - k;
				helper_matrix[k][j] = -1;
			}
		}
		else
		{
			if (helper_matrix[size - 1][j] == -1 && map_matrix[size - 1][j] > size - \
					input_matrix[1][j] + 1)
				return (-1);
			helper_matrix[size - 1][j] = size - input_matrix[1][j] + 1;
		}
	}
	return (0);
}

static int	optimizer_left(int **map_matrix, int **input_matrix, \
							int **helper_matrix, int size)
{
	int	j;
	int	k;

	j = -1;
	while (input_matrix[2][++j] != 0)
	{
		k = -1;
		if (input_matrix[2][j] == 1)
		{
			if (helper_matrix[j][0] == -1 && map_matrix[j][0] != size)
				return (-1);
			helper_matrix[j][0] = -1;
			map_matrix[j][0] = size;
		}
		else if (input_matrix[2][j] == size)
		{
			while (map_matrix[j][++k] != 0)
			{
				if (helper_matrix[j][k] == -1 && map_matrix[j][k] != k + 1)
					return (-1);
				map_matrix[j][k] = k + 1;
				helper_matrix[j][k] = -1;
			}
		}
		else
		{
			if (helper_matrix[j][0] == -1 && map_matrix[j][0] > size - \
					input_matrix[2][j] + 1)
				return (-1);
			helper_matrix[j][0] = size - input_matrix[2][j] + 1;
		}
	}
	return (0);
}

static int	optimizer_right(int **map_matrix, int **input_matrix, \
							int **helper_matrix, int size)
{
	int	j;
	int	k;

	j = -1;
	while (input_matrix[3][++j] != 0)
	{
		k = -1;
		if (input_matrix[3][j] == 1)
		{
			if (helper_matrix[j][size - 1] == -1 && map_matrix[j][size - 1] != size)
				return (-1);
			helper_matrix[j][size - 1] = -1;
			map_matrix[j][size - 1] = size;
		}
		else if (input_matrix[3][j] == size)
		{
			while (map_matrix[j][++k] != 0)
			{
				if (helper_matrix[j][k] == -1 && map_matrix[j][k] != size - k)
					return (-1);
				map_matrix[j][k] = size - k;
				helper_matrix[j][k] = -1;
			}
		}
		else
		{
			if (helper_matrix[j][size - 1] == -1 && map_matrix[j][size - 1] > size - \
					input_matrix[3][j] + 1)
				return (-1);
			helper_matrix[j][size - 1] = size - input_matrix[3][j] + 1;
		}
	}
	return (0);
}

int	fill_helper_matrix(int **map_matrix, int **input_matrix, \
							int **helper_matrix, int size)
{
	int	status;

	fill_0(helper_matrix, size);
	status = optimizer_up(map_matrix, input_matrix, helper_matrix, size);
	if (status == -1)
	{
		ft_putstr("ERROR: Solution does not exist!\n");
		return (0);
	}
	status = optimizer_down(map_matrix, input_matrix, helper_matrix, size);
	if (status == -1)
	{
		ft_putstr("ERROR: Solution does not exist!\n");
		return (0);
	}
	status = optimizer_left(map_matrix, input_matrix, helper_matrix, size);
	if (status == -1)
	{
		ft_putstr("ERROR: Solution does not exist!\n");
		return (0);
	}
	status = optimizer_right(map_matrix, input_matrix, helper_matrix, size);
	if (status == -1)
	{
		ft_putstr("ERROR: Solution does not exist!\n");
		return (0);
	}
	return (1);
}
