/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_input_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:28:25 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/15 17:36:01 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	check_size_and_1(int **input_matrix, int size)
{
	int	status;
	int	j;

	status = 0;
	j = -1;
	while (++j < size)
	{
		if (input_matrix[0][j] == size && input_matrix[1][j] != 1)
			status = -10;
		if (input_matrix[1][j] == size && input_matrix[0][j] != 1)
			status = -10;
		if (input_matrix[2][j] == size && input_matrix[3][j] != 1)
			status = -10;
		if (input_matrix[3][j] == size && input_matrix[2][j] != 1)
			status = -10;
	}
	if (status == 0)
		return (1);
	ft_putstr("ERROR: Solution does not exist!\n");
	return (0);
}

static int	check_plus_minus(int **input_matrix, int size)
{
	int	status;
	int	j;

	status = 0;
	j = -1;
	while (++j < size)
	{
		if (input_matrix[0][j] + input_matrix[1][j] > size + 1)
			status = -10;
		if (input_matrix[2][j] + input_matrix[3][j] > size + 1)
			status = -10;
		if (input_matrix[0][j] + input_matrix[1][j] < 3)
			status = -10;
		if (input_matrix[2][j] + input_matrix[3][j] < 3)
			status = -10;
	}
	if (status == 0)
		return (check_size_and_1(input_matrix, size));
	ft_putstr("ERROR: Solution does not exist!\n");
	return (0);
}

static int	check_angles(int **input_matrix, int size)
{
	int	status;

	status = 0;
	if (input_matrix[0][0] == 1 || input_matrix[2][0] == 1)
		if (input_matrix[0][0] != input_matrix[2][0])
			status = -10;
	if (input_matrix[0][size - 1] == 1 || input_matrix[3][0] == 1)
		if (input_matrix[0][size - 1] != input_matrix[3][0])
			status = -10;
	if (input_matrix[1][0] == 1 || input_matrix[2][size - 1] == 1)
		if (input_matrix[1][0] != input_matrix[2][size - 1])
			status = -10;
	if (input_matrix[1][size - 1] == 1 || input_matrix[3][size - 1] == 1)
		if (input_matrix[1][size - 1] != input_matrix[3][size - 1])
			status = -10;
	if (status == 0)
		return (check_plus_minus(input_matrix, size));
	ft_putstr("ERROR: Solution does not exist!\n");
	return (0);
}

static int	check_values(int **input_matrix, int size)
{
	int	status;
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		status = 0;
		j = -1;
		while (++j < size)
			if (input_matrix[i][j] == 1)
				++status;
		if (status != 1)
		{
			ft_putstr("ERROR: Solution does not exist!\n");
			return (0);
		}
	}
	return (check_angles(input_matrix, size));
}

int	fill_input_matrix(char *argv, int **input_matrix, int size)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (input_matrix[++i] != 0)
	{
		j = -1;
		while (++j < size)
		{
			while (!(argv[k] == '\0' || argv[k] != ' '))
				++k;
			if (argv[k] - 48 > size)
			{
				ft_putstr("ERROR: ");
				ft_putstr(&argv[k]);
				ft_putstr(": Argument is not valid!\n");
				return (0);
			}
			input_matrix[i][j] = argv[k] - 48;
			++k;
		}
	}
	return (check_values(input_matrix, size));
}
