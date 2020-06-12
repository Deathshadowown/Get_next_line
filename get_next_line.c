/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:10:15 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/12 20:20:02 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

#include <stdio.h> //remove later

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

static int read_from_line(int ret, int fd, char **string, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while (string[fd][len] != '\0' && string[fd][len] != '\n')
	len++;
	if (string[fd][len] == '\n')
	{
		*line = ft_strsub(string[fd], 0, len);
		temp = ft_strdup(&(string[fd][len + 1]));
		free(string[fd]);
		string[fd] = temp;
		if (string[fd][0] == '\0')
		ft_strdel(&string[fd]);
	}
	else
	{
		*line = ft_strdup(string[fd]);
		ft_strdel(&string[fd]);
	}
	return (1);
}

int get_next_line(const int fd, char **line)
{
	static char *string[255];
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	int			ret;

	ret = 0;
	if (fd < 0 || line == NULL)
	return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (string[fd] == NULL)
		string[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(string[fd], buff);
			free(string[fd]);
			string[fd] = temp;
		}
		if (ft_strchr(buff, '\n'))
		break;
	}
	if (ret < 0)
	return (-1);
	else if (ret == 0 && string[fd] == NULL)
	return (0);
	return (read_from_line(ret, fd, string, line));
}

// testing
int	main()
{
	int		fd;
	int		ret;
	char	*line;

	
	fd = open("text2.txt", O_RDONLY);
	if (fd == -1){
		ft_putstr("error\n");
		return (1);
	}
	while (ret = get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
		printf("get next line\n");
	}
	if (close(fd) == -1)
	{
		write(1, "errorend\n",9);
		return (1);
	}
	return (0);
}
