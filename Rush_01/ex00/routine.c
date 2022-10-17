/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:24:17 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/17 17:03:21 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	change_value(t_matrix *tmp, t_matrix *matrixes, int *cell, int z)
{
	tmp->map_matrix[cell[0]][cell[1]] = \
		matrixes->helper_matrix[cell[0]][cell[1]][z];
	if (tmp->helper_matrix[cell[0]][cell[1]] != 0)
	{
		free(tmp->helper_matrix[cell[0]][cell[1]]);
		tmp->helper_matrix[cell[0]][cell[1]] = 0;
	}
}

static int	solve(t_matrix *tmp, t_matrix *matrixes, int *cell, int size)
{
	matrixes->map_matrix[cell[0]][cell[1]] = tmp->map_matrix[cell[0]][cell[1]];
	free(matrixes->helper_matrix[cell[0]][cell[1]]);
	matrixes->helper_matrix[cell[0]][cell[1]] = 0;
	cross_clear(matrixes, size);
	return (1);
}

static int	set_random(t_matrix *tmp, t_matrix *matrixes, int size, int *cell)
{
	int			status;
	int			z;

	z = -1;
	status = -1;
	while (++z < size)
	{
		if (matrixes->helper_matrix[cell[0]][cell[1]][z] == -10)
			continue ;
		change_value(tmp, matrixes, cell, z);
		status = routine(tmp, size);
		if (status == 1)
			return (solve(tmp, matrixes, cell, size));
		else if (status == -1)
		{
			free_all(tmp, size);
			if (init_struct(tmp, size) == 0 || \
					deep_copy(matrixes, tmp, size) == -1)
			{
				free_all(tmp, size);
				return (0);
			}
		}
	}
	return (status);
}

static int	try_random(t_matrix *matrixes, int size)
{
	t_matrix	tmp;
	int			status;
	int			*cell;

	if (init_struct(&tmp, size) == 0 || deep_copy(matrixes, &tmp, size) == -1)
	{
		free_all(&tmp, size);
		return (0);
	}
	cell = find_min_random(&tmp, size);
	if (cell == 0)
		return (0);
	else if (cell[0] == -1)
	{
		free_all(&tmp, size);
		free(cell);
		return (-1);
	}
	status = set_random(&tmp, matrixes, size, cell);
	free(cell);
	free_all(&tmp, size);
	return (status);
}

int	routine(t_matrix *matrixes, int size)
{
	int	status;
	int	count;

	count = 1;
	status = 0;
	cross_clear(matrixes, size);
	while (count != 0)
	{
		count = 0;
		count += find_unique(matrixes, size);
		count += if_only(matrixes, size);
	}
	status = check_map(matrixes, size);
	if (status == 0)
	{
		status = try_random(matrixes, size);
		if (status == 0)
			return (0);
		else if (status == 1)
			routine(matrixes, size);
	}
	return (status);
}
