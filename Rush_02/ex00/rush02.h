/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:09:07 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/18 16:45:23 by vismaily         ###   ########.fr       */
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

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
size_t		ft_strlen(const char *str);
char		**ft_split(const char *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);

char		*parse_number(char *str);
char		*read_all(char *dict_name);
void		run(char *dict, char *number);
t_dict		**get_dict(char *dict);

#endif
