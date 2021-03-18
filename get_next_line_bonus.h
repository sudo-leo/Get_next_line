/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:02:20 by larmelli          #+#    #+#             */
/*   Updated: 2021/02/05 16:04:53 by larmelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_list{
	int			rd;
	char		buf[BUFFER_SIZE + 1];
}				t_list;

int				get_next_line(int fd, char **line);
int				len(char *s);
int				nl_check(char *saved);
char			*ft_strjoin(char *s1, char *s2);
char			*until_nl(char *str, char c);
char			*after_nl(char *str);

#endif
