/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:12:03 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/05 20:43:42 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# include <sys/uio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);
char	*ft_chrsub(char const *s, unsigned int c);

#endif
