/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:31:59 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/10 13:59:20 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

static int	parsing_size(int size)
{
	int	i;

	i = 3;
	while (++i != 10)
		if (size == i * i)
			return (i);
	return (-1);
}

int	parsing_argv(char *argv)
{
	int	size;
	int	i;

	size = 0;
	i = -1;
	while (argv[++i] != 0)
	{
		while (argv[i] == ' ')
			++i;
		if (ft_strchr("123456789", argv[i]) && \
				(argv[i + 1] == ' ' || argv[i + 1] == '\0'))
			++size;
		else if (argv[i] == '\0')
			break ;
		else
			return (-1);
	}
	size = parsing_size(size);
	return (size);
}
