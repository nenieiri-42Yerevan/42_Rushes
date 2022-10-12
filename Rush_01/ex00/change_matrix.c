/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:50:08 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/12 16:13:03 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	change_again_col(int **map_matrix)
{
	int	i;
	int	j;
	int	m;

	j = -1;
	while (map_matrix[0][++j] != 0)
	{
		i = 0;
		while (map_matrix[i + 1] != 0)
		{
			m = i + 1;
			while (map_matrix[m] != 0)
			{
				if (map_matrix[i][j] == map_matrix[m][j])
					return (-1);
				++m;
			}
			++i;
		}
	}
	return (0);
}

static int	change_again_row(int **map_matrix)
{
	int	i;
	int	j;
	int	m;

	i = -1;
	while (map_matrix[++i] != 0)
	{
		j = 0;
		while (map_matrix[i][j + 1] != 0)
		{
			m = j + 1;
			while (map_matrix[i][m] != 0)
			{
				if (map_matrix[i][j] == map_matrix[i][m])
					return (-1);
				++m;
			}
			++j;
		}
	}
	return (change_again_col(map_matrix));
}

int	change_matrix(int **map_matrix, int **helper_matrix)
{
	int	i;
	int	j;

	i = -1;
//	print_map(map_matrix);
//	usleep(100);
//	ft_putchar('\n');
	while (map_matrix[++i] != 0)
	{
		j = -1;
		while (map_matrix[i][++j] != 0)
		{
			if (map_matrix[i + 1] == 0 && map_matrix[i][j + 1] == 0 && \
					(map_matrix[i][j] == helper_matrix[i][j] || helper_matrix[i][j] == -1))
				return (-1);
			if (helper_matrix[i][j] == -1)
				continue ;
			if (map_matrix[i][j] >= helper_matrix[i][j])
				map_matrix[i][j] = 1;
			else if (map_matrix[i][j] < helper_matrix[i][j])
			{
				map_matrix[i][j] += 1;
				if (change_again_row(map_matrix) == -1)
					change_matrix(map_matrix, helper_matrix);
				return (0);
			}
		}
	}
	return (0);
}
