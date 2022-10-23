/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_spaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 10:58:12 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/23 12:08:17 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	change_to_space(t_dict **dict)
{
	int	i;
	int	j;

	i = -1;
	while (dict[++i] != 0)
	{
		j = -1;
		while (dict[i]->value[++j] != 0)
		{
			if (dict[i]->value[j] == '\r' || dict[i]->value[j] == '\t' || \
					dict[i]->value[j] == '\v' || dict[i]->value[j] == '\v')
				dict[i]->value[j] = ' ';
		}
	}
}

static void	split_and_join(char **split_value, t_dict **dict, int i)
{
	char	*tmp;
	int		j;

	j = -1;
	while (split_value[++j] != 0)
	{
		if (j == 0)
		{
			dict[i]->value = split_value[j];
			continue ;
		}
		tmp = ft_strjoin(dict[i]->value, " ");
		free(dict[i]->value);
		dict[i]->value = tmp;
		tmp = ft_strjoin(dict[i]->value, split_value[j]);
		free(dict[i]->value);
		free(split_value[j]);
		dict[i]->value = tmp;
	}
}

int	rm_spaces(t_dict **dict)
{
	char	**split_value;
	int		i;

	i = -1;
	change_to_space(dict);
	while (dict[++i] != 0)
	{
		split_value = ft_split(dict[i]->value, ' ');
		free(dict[i]->value);
		split_and_join(split_value, dict, i);
		free(split_value);
	}
	return (1);
}
