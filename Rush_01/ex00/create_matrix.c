/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:19:01 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/10 14:49:35 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

static void	free_matrix(char **matrix, int i)
{
	while (i != -1)
	{
		i = i - 1;
		free(matrix[i]);
		matrix[i] = 0;
	}
	free(matrix);
	matrix = 0;
}

static void	fill_matrix(char **matrix, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			matrix[i][j] = 1;
	}
}

char	**create_matrix(int size)
{
	char	**matrix;
	int		i;

	i = -1;
	matrix = (char **)malloc(sizeof(char *) * (size + 1));
	if (!matrix)
		return (0);
	matrix[size] = 0;
	while (matrix[++i] != 0)
	{
		matrix[i] = (char *)malloc(sizeof(int) * (size + 1));
		if (!matrix)
		{
			free_matrix(matrix, i);
			return (0);
		}
	}
	fill_matrix(matrix, size);
	return (matrix);
}
