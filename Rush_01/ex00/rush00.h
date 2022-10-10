/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:55:42 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/10 15:25:02 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH00_H
# define RUSH00_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_strchr(const char *str, int c);
int		parsing_argv(char *argv);
char	**create_map_matrix(int size);
void	print_map(char **matrix);
int		check_map(char **map_matrix, char **input_matrix);

#endif
