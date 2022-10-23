/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:00:59 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/23 12:07:15 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static char	*fill_tab(int n)
{
	int		i;
	char	*tab;

	tab = (char *)malloc(sizeof(char) * (((n * 3) + 1) + 1));
	if (!tab)
		return (0);
	i = -1;
	tab[++i] = '1';
	while (++i < (n * 3) + 1)
		tab[i] = '0';
	tab[i] = '\0';
	return (tab);
}

int	display_zero(int n, t_dict **dict)
{
	int		i;
	char	*tab;

	tab = fill_tab(n);
	if (tab == 0)
		return (0);
	i = -1;
	while (dict[++i] != 0)
	{
		if (ft_strcmp(tab, dict[i]->key) == 0)
		{
			ft_putstr_fd(" ", 1);
			ft_putstr_fd(dict[i]->value, 1);
			free(tab);
			tab = 0;
			return (1);
		}
	}
	if (tab != 0)
		free(tab);
	return (0);
}
