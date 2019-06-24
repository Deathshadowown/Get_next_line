/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 14:12:03 by svan-nie          #+#    #+#             */
/*   Updated: 2019/06/24 14:28:07 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <sys/uio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

int	get_next_line(const int fd, char **line);

#endif
