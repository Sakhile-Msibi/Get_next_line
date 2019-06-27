/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_newline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smsibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 07:53:37 by smsibi            #+#    #+#             */
/*   Updated: 2019/06/27 09:01:54 by smsibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_newline(char **paragraph, char **line)
{
	char	*temp_paragraph;
	char	*check_paragraph;
	int		i;

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
