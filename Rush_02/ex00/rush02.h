/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:09:07 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/22 14:38:34 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdio.h>

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_dict
{
	char	*key;
	char	*value;
}			t_dict;

typedef	struct	s_trio
{
	char *hundred_units;
	char *hundred;
	char *dozen;
	char *unit;
}				t_trio;

void		ft_putstr_fd(char *str, int fd);
size_t		ft_strlen(const char *str);
char		**ft_split(const char *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_strcmp(char *s1, char *s2);

char		*parse_number(char *str);
char		*read_all(char *dict_name);
void		run(char *dict, char *number);
t_dict		**get_dict(char *dict);
void		free_arr(char **arr);
char		*fill(char *dest, char *number);
char		*format_string(char *str);
t_trio		*trio_to_struct(char *str);
void		free_trio(t_trio *trio);
int			display_zero(int n, t_dict **dict);


#endif
