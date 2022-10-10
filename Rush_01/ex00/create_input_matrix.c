/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_input_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:28:25 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/10 16:31:27 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

static void	fill_input_matrix(char *argv, char **input_matrix, int size)
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
			while (!(argv[k] != '\0' && argv[k] != ' '))
				++k;
			input_matrix[i][j] = argv[k++] - 48;
		}
	}
}

char	**create_input_matrix(char *argv, int size)
{
	char	**input_matrix;
	int		i;

	i = -1;
	input_matrix = (char **)malloc(sizeof(char *) * 5);
	if (!input_matrix)
		return (0);
	input_matrix[4] = 0;
	while (++i != 4)
	{
		input_matrix[i] = (char *)malloc(sizeof(int) * (size + 1));
		if (!input_matrix)
		{
			free_matrix(input_matrix, i);
			return (0);
		}
		input_matrix[i][size] = 0;
	}
	fill_input_matrix(argv, input_matrix, size);
	return (input_matrix);
}
