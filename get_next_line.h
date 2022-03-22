/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 02:03:37 by slahrach          #+#    #+#             */
/*   Updated: 2022/02/08 02:11:49 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"

size_t		t_strlen(char *s);
char		*ft_strnchr(char *s, int c, int *i);
char		*fre_strjoin(char *s1, char *s2);
char		*t_strdup(char *s1);
size_t		t_strlcpy(char *dst, char *src, size_t sizedst);
char		*t_strchr(char *s, int c);
char		*get_next_line(int fd);
#endif