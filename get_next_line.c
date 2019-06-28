/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 09:34:33 by smsibi            #+#    #+#             */
/*   Updated: 2019/06/28 06:47:10 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "Get_next_line.h"

static int	ft_check_newline(char **paragraph, char **line)
{
    char    *temp_paragraph;
    char    *check_paragraph;
    int     i;

    i = 0;
    check_paragraph = *paragraph;
    while (check_paragraph[i] != '\n')
    {
        if (!check_paragraph[i++])
            return (0);
    }
    temp_paragraph = &check_paragraph[i];
    *temp_paragraph = '\0';
    *line = ft_strdup(*paragraph);
    *paragraph = ft_strdup(temp_paragraph + 1);
    return (1);
}

static int	ft_read_file(char **paragraph, char **line, char *page, const int fd)
{
    int     ret;
    char    *temp_paragraph;

    while ((ret = read(fd, page, BUFF_SIZE)) > 0)
    {
        page[ret] = '\0';
        if (*paragraph)
        {
            temp_paragraph = *paragraph;
            *paragraph = ft_strjoin(temp_paragraph, page);
            free(temp_paragraph);
            temp_paragraph = NULL;
        }
        else
            *paragraph = ft_strdup(page);
        if (ft_check_newline(paragraph, line))
            break ;
    }
    return (RET_VALUE(ret));
}

int			get_next_line(const int fd, char **line)
{
	static char	*paragraph[MAX_FD];
	char		*page;
	int			ret;
	int			i;

	if ((fd < 0 || fd >= MAX_FD) || !line || (read(fd, paragraph[fd], 0) < 0)\
			|| !(page = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	if (paragraph[fd])
		if (ft_check_newline(&paragraph[fd], line))
			return (1);
	i = 0;
	while (i < BUFF_SIZE)
		page[i++] = '\0';
	ret = ft_read_file(&paragraph[fd], line, page , fd);
	free(page);
	if (ret != 0 || paragraph[fd] == NULL || paragraph[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = paragraph[fd];
	paragraph[fd] = NULL;
	return (1);
}
