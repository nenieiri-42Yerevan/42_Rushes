/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:29:21 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/15 17:52:21 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	init(t_matrix *matrixes, int size)
{
	matrixes->map_matrix = create_matrix_2d(size, size);
	if (matrixes->map_matrix == 0)
		return (0);
	matrixes->input_matrix = create_matrix_2d(4, size);
	if (matrixes->input_matrix == 0)
	{
		free_matrix_2d(matrixes->map_matrix, size);
		return (0);
	}
	matrixes->helper_matrix = create_matrix_3d(size, size);
	if (matrixes->helper_matrix == 0)
	{
		free_matrix_2d(matrixes->map_matrix, size);
		free_matrix_2d(matrixes->input_matrix, size);
		return (0);
	}
	fill_map_matrix(matrixes->map_matrix, size);
	return (1);
}

static int	free_all(t_matrix *matrixes, int size)
{
	free_matrix_2d(matrixes->input_matrix, 4);
	free_matrix_2d(matrixes->map_matrix, size);
	free_matrix_3d(matrixes->helper_matrix, size);
	return (0);
}

static int	routine(t_matrix *matrixes, int size)
{
	int	status;
	int	count;

	count = 1;
	status = 0;
	while (count != 0)
	{
		count = 0;
		count += find_unique(matrixes, size);
		count += cross_clear(matrixes, size);
	}
	status = check_map(matrixes, size);
	return (status);
}

static int	rush00(char **argv, int size)
{
	int			status;
	t_matrix	matrixes;

	status = 0;
	if (init(&matrixes, size) == 0)
		return (free_all(&matrixes, size));
	if (fill_input_matrix(argv[1], matrixes.input_matrix, size) == 0)
		return (free_all(&matrixes, size));
	if (fill_helper_matrix(&matrixes, size) == 0)
		return (free_all(&matrixes, size));
	status = routine(&matrixes, size);
	while (status == 0)
	{
		status = change_matrix(&matrixes, size);
		while (status == 1)
			status = change_matrix(&matrixes, size);
		if (status == -1)
		{
			ft_putstr("ERROR: Solution does not exist!\n");
			break ;
		}
		status = check_map(&matrixes, size);
	}
	if (status == 1)
		print_map(matrixes.map_matrix);
	free_all(&matrixes, size);
	return (0);
}

int	main(int argc, char **argv)
{
	int		size;

	size = 0;
	if (argc == 2)
	{
		size = parsing_argv(argv[1]);
		if (size == -1)
			ft_putstr("ERROR: Arguments are not valid!\n");
		else
			return (rush00(argv, size));
	}
	else
		ft_putstr("ERROR: Number of arguments is wrong!\n");
	return (0);
}
