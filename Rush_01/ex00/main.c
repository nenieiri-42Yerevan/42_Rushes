/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:29:21 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/12 16:36:05 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	init(int ***map_matrix, int ***input_matrix, int ***helper_matrix, \
					int size)
{
	*map_matrix = create_matrix(size, size);
	if (*map_matrix == 0)
		return (0);
	*input_matrix = create_matrix(4, size);
	if (*input_matrix == 0)
	{
		free_matrix(*map_matrix, size);
		return (0);
	}
	*helper_matrix = create_matrix(size, size);
	if (*helper_matrix == 0)
	{
		free_matrix(*map_matrix, size);
		free_matrix(*input_matrix, size);
		return (0);
	}
	fill_map_matrix(*map_matrix, size);
	return (1);
}

static int	rush00(char **argv, int size)
{
	int	status;
	int	**map_matrix;
	int	**input_matrix;
	int	**helper_matrix;

	status = 0;
	map_matrix = 0;
	input_matrix = 0;
	helper_matrix = 0;
	if (init(&map_matrix, &input_matrix, &helper_matrix, size) == 0)
		return (0);
	if (fill_input_matrix(argv[1], input_matrix, size) == 0)
		return (0);
	if (fill_helper_matrix(map_matrix, input_matrix, helper_matrix, size) == 0)
		return (0);
//	status = check_map(map_matrix, input_matrix, size);
//	while (status == 0)
//	{
//		if (change_matrix(map_matrix, helper_matrix) == -1)
//		{
//			ft_putstr("ERROR: Solution does not exist!\n");
//			break ;
//		}
//		status = check_map(map_matrix, input_matrix, size);
//	}
//	if (status == 1)
//		print_map(map_matrix);
	free_matrix(input_matrix, 4);
	free_matrix(map_matrix, size);
	free_matrix(helper_matrix, size);
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
