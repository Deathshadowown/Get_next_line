/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:10:15 by svan-nie          #+#    #+#             */
/*   Updated: 2019/06/24 14:59:26 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	static char	*buff;
	char		*temp;
	int			ret;
	int			i;

	i = 0;
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ft_strchr(buff, '\n'))
		{
			//while (buff[i] != '\n')
			//{
			//	ft_putstr(&buff[i++]);
				//*line = &buff[i++];
			//}
			//temp = ft_strjoin(temp, buff);
			if (!(temp = ft_strjoin(*line, buff)))
				return (-1);
			if (ft_strsub(temp, 0, ft_strlen(buff))
					*line = &buff[i];
		}
		buff[ret] = '\0';
		*line = buff;
	}
	return (ret);
}

int	main()
{
	int	fd;
	char	*line;

	fd = open("name", 'r');
	get_next_line(fd, &line);
	printf("%s", &line[0]);
}
