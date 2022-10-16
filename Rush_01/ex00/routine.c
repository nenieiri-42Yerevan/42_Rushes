/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:24:17 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/16 13:56:31 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

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

	status = routine(&tmp, size);
	if (status == 1)
	{
	}
	free_all(&tmp, size);
}

int	routine(t_matrix *matrixes, int size)
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
	if (status == 0)
	{
		status = try_random(matrixes, size);
		if (status == 0)
			return (0);
		else if (status == 1)
		{
			routine(matrixes, size);
		}
	}
	return (status);
}
