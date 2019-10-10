/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malallai <malallai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:16:21 by malallai          #+#    #+#             */
/*   Updated: 2019/01/08 11:58:25 by malallai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_line(int fd, char *buffer, char **file)
{
	int		r;
	char	*temp;

	while ((r = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[r] = '\0';
		temp = *file;
		*file = ft_strjoin(temp, buffer);
		ft_strdel(&temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	ft_strdel(&buffer);
	return (r == -1 ? 0 : 1);
}

int			ft_get_next_line(const int fd, char **line)
{
	static char		*files[10240];
	char			*buffer;
	char			*temp;
	char			*temp2;

	buffer = ft_strnew(BUFF_SIZE);
	if (fd > 10240 || fd < 0 || line == NULL || buffer == NULL
		|| BUFF_SIZE < 1)
		return (-1);
	if (!files[fd])
		files[fd] = ft_strnew(1);
	if (!get_line(fd, buffer, &files[fd]))
		return (-1);
	if ((temp = ft_strchr(files[fd], '\n')))
	{
		*line = ft_strsub(files[fd], 0, temp - files[fd]);
		temp2 = files[fd];
		files[fd] = ft_strdup(temp + 1);
		ft_strdel(&temp2);
		return (1);
	}
	*line = ft_strdup(files[fd]);
	ft_strdel(&files[fd]);
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
