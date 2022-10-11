/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_input_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:28:25 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/11 13:32:00 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

static int	fill_input_matrix(char *argv, char **input_matrix, int size)
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
			if (argv[k] - 48 > size)
			{
				ft_putstr("ERROR: ");
				ft_putstr(&argv[k]);
				ft_putstr(": Argument is not valid!\n");
				return (-1);
			}
			input_matrix[i][j] = argv[k++] - 48;
		}
	}
	return (0);
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
	if (fill_input_matrix(argv, input_matrix, size) == -1)
	{
		free_matrix(input_matrix, i);
		return (0);
	}
	return (input_matrix);
}
