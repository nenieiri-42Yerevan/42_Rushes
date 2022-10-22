/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:45:32 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/22 15:20:33 by vismaily         ###   ########.fr       */
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

static void	free_dict(t_dict **dict, int j)
{
	int	i;

	i = -1;
	if (dict == 0)
		return ;
	while (++i < j)
	{
		free(dict[i]);
		dict[i] = 0;
	}
	free(dict);
	dict = 0;
}

static int	save_values(char **dict_lines, int i, int j, t_dict **dict)
{
	char	*tmp;
	char	**split_value;

	split_value = ft_split(dict_lines[i], ':');
	dict[j] = (t_dict *)malloc(sizeof(t_dict) * 1);
	if (!dict[j])
	{
		free_dict(dict, j);
		return (0);
	}
	tmp = ft_strtrim(split_value[0], " ");
	free(split_value[0]);
	dict[j]->key = tmp;
	tmp = ft_strtrim(split_value[1], " ");
	free(split_value[1]);
	dict[j]->value = tmp;
	free(split_value);
	return (1);
}

static t_dict	**get_dict_arr(char **dict_lines)
{
	t_dict	**dict;
	int		size;
	int		i;
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
		if (save_values(dict_lines, i, j++, dict) == 0)
			return (0);
	}
	return (dict);
}

t_dict	**get_dict(char *dict)
{
	t_dict	**my_dict;
	char	**lines;

	lines = ft_split(dict, '\n');
	if (!lines)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	my_dict = get_dict_arr(lines);
	free_arr(lines);
	free(dict);
	return (my_dict);
}
