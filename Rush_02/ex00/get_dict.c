/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:45:32 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/18 16:45:53 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	dict_size(char **dict_lines)
{
	int	i;
	int	size;

	size = 0;
	i = -1;
	while (dict_lines[++i] != '\0')
	{
		if (ft_strchr(dict_lines[i], ':') != 0)
			++size;
	}
	return (size);
}

static t_dict	**get_dict_arr(char **dict_lines)
{
	t_dict	**dict;
	int		size;
	int		i;
	char	**split_value;
	int		j;

	size = dict_size(dict_lines);
	dict = (t_dict **)malloc(sizeof(t_dict *) * (size + 1));
	if (!dict)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	dict[size] = 0;
	i = -1;
	j = 0;
	while (dict_lines[++i] != 0)
	{
		if (ft_strchr(dict_lines[i], ':') == 0)
			continue ;
		split_value = ft_split(dict_lines[i], ':');
		if (dict_lines == 0)
			continue ;
		free(dict_lines[i]);
		dict[j] = (t_dict *)malloc(sizeof(t_dict) * 1);
		dict[j]->key = ft_strtrim(split_value[0], " ");
		dict[j]->value = ft_strtrim(split_value[1], " ");
		++j;
	}
	return (dict);
}

t_dict	**get_dict(char *dict)
{
	char	**lines;

	lines = ft_split(dict, '\n');
	if (!lines)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	free(dict);
	return (get_dict_arr(lines));
}
