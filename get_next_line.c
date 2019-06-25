/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:10:15 by svan-nie          #+#    #+#             */
/*   Updated: 2019/06/25 16:19:37 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

#include <stdio.h>

char	*ft_chrsub(char const *s, unsigned int c)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (s[i] != c)
		i++;
	if (!s || !(ptr = ft_strnew(i)))
		return (NULL);
	if (!(ft_strncpy(ptr,s , i)))
		return (NULL);
	return (ptr);
}

int	get_next_line(const int fd, char **line)
{
	static char	*buff;
	char		*temp;
	int			ret;
	int			i;
	//static char	buff[BUFF_SIZE + 1];
	i = 0;
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!(temp = ft_strjoin(temp, buff)))
			return (-1);
		if	((ft_strchr(temp, '\n') && ft_strchr(buff, '\n')))
		{
		//	if (!(*line = ft_chrsub(temp, '\n')))
		//		return (-1);
			break ;
		}
		//buff[ret] = '\0';
		//*line = temp;
	}
	if (!(*line = ft_chrsub(temp, '\n')))
		return (-1);
	if (*temp)
		free(temp);
	*line = temp;
	return (1);
}

int	main()
{
	int	fd;
	char	*line;
	char	*line2;

	fd = open("name", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);
//	printf("\n");
	get_next_line(fd, &line2);
	printf("%s", line2);
}
