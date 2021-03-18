/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:38:41 by larmelli          #+#    #+#             */
/*   Updated: 2021/02/05 15:52:09 by larmelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	appoggio(int fd, char **line, t_list *var, char **saved)
{
	while (1)
	{
		if ((!(*saved) || !(nl_check(*saved))))
		{
			if ((var->rd = read(fd, var->buf, BUFFER_SIZE)) == 0)
			{
				*line = until_nl(*saved, '\0');
				free(*saved);
				*saved = 0;
				return (0);
			}
			if (var->rd == -1)
				return (-1);
			var->buf[var->rd] = 0;
			*saved = ft_strjoin(*saved, var->buf);
		}
		if (nl_check(*saved))
		{
			*line = until_nl(*saved, '\n');
			*saved = after_nl(*saved);
			return (1);
		}
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	t_list		var;
	static char	*saved;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 255 || line == NULL)
		return (-1);
	if (saved == NULL)
	{
		if (!(saved = malloc(sizeof(char) * (len(var.buf) + len(saved) + 1))))
			return (-1);
		saved[0] = 0;
	}
	return (appoggio(fd, &(*line), &var, &saved));
}
