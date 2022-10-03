/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:45:41 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/03 17:52:01 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++j <= y)
	{
		while (++i <= x)
		{
			if ((i == 1 && j == 1) || (j == y && i == x && j != 1 && i != 1))
				ft_putchar('/');
			else if ((j == y && i == 1) || (j == 1 && i == x))
				ft_putchar('\\');
			else if (j == 1 || i == 1 || j == y || i == x)
				ft_putchar('*');
			else
				ft_putchar(' ');
		}
		i = 0;
		ft_putchar('\n');
	}
}
