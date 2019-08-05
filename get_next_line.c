/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:38:51 by smsibi            #+#    #+#             */
/*   Updated: 2019/08/05 09:30:15 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int	get_next_line(const int fd, char **line)
{
	static char	*buf[2147483647];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	ssize_t		ret;
	int			newl;

	if (fd < 0 || (!buf[fd] && !(buf[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!ft_strchr(buf[fd], '\n') && (ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		temp = buf[fd];
		buf[fd] = ft_strjoin(buf[fd], buffer);
		ft_strdel(&temp);
	}
	if (ret == -1 || !*(temp = buf[fd]))
		return (ret == -1 ? -1 : 0);
	if ((newl = (ft_strchr(buf[fd], '\n') > 0)))
		*line = ft_strsub(buf[fd], 0, ft_strchr(buf[fd], '\n') - buf[fd]);
	else
		*line = ft_strdup(buf[fd]);
	buf[fd] = ft_strsub(buf[fd], (unsigned int)(ft_strlen(*line) + newl),
			(size_t)(ft_strlen(buf[fd]) - (ft_strlen(*line) + newl)));
	ft_strdel(&temp);
	return (!(!buf[fd] && !ft_strlen(*line)));
}
