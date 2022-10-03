/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:05:32 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/03 15:40:48 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++j <= y)
	{
		while (++i <= x)
		{
			if ((i == 1 || i == x) && (j != 1 && j != y))
				ft_putchar('|');
			else if ((j == 1 || j == y) && (i != 1 && i != x))
				ft_putchar('-');
			else if (i == 1 || i == x || j == 1 || j == y)
				ft_putchar('o');
			else
				ft_putchar(' ');
		}
		i = 0;
		ft_putchar('\n');
	}
}
