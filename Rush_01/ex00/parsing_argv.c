/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:31:59 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/15 18:12:46 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

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
	if (size % 4 != 0)
		return (-1);
	size /= 4;
	if (size < 2 || size > 9)
		return (-1);
	return (size);
}
