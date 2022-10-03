/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:06:01 by vismaily          #+#    #+#             */
/*   Updated: 2020/11/29 17:06:05 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (j <= y)
	{
		while (i <= x)
		{
			if (j == 1 && (i == 1 || i == x))
				ft_putchar('A');
			else if (j == y && (i == 1 || i == x))
				ft_putchar('C');
			else if (j == 1 || i == 1 || j == y || i == x)
				ft_putchar('B');
			else
				ft_putchar(' ');
			i++;
		}
		i = 1;
		ft_putchar('\n');
		j++;
	}
}
