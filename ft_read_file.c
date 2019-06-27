/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 09:04:01 by smsibi            #+#    #+#             */
/*   Updated: 2019/06/27 09:16:06 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_read_file(char **paragraph, char **line, char *page, const int fd)
{
	int		ret;
	char	*temp_paragraph;

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
		if (check_newline(paragraph, line))
			break ;
	}
	return (RET_VALUE);
}
