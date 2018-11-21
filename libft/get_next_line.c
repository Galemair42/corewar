/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabt <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:29:45 by jabt              #+#    #+#             */
/*   Updated: 2018/03/29 09:48:00 by jabt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "get_next_line.h"
#include "libft.h"

static	char			*ft_joinchar(char *tmp, char **file)
{
	char	*save;

	if (*file)
		save = *file;
	else
	{
		*file = malloc(1);
		**file = '\0';
		save = *file;
	}
	if (!(*file = ft_strjoin(*file, tmp)))
		return (NULL);
	free(save);
	return (*file);
}

static	int				ft_readfile(const int fd, char **file)
{
	int		ret;
	char	*tmp;
	int		retswap;

	retswap = 0;
	if (!(tmp = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while (tmp && (ret = read(fd, tmp, BUFF_SIZE)) != 0 && ret != -1)
	{
		tmp[ret] = '\0';
		retswap += ret;
		if (!(ft_joinchar(tmp, file)))
			return (-1);
		if ((ft_strchr(*file, '\n')))
		{
			ft_strdel(&tmp);
			return (1);
		}
	}
	free(tmp);
	if (ret == -1)
		return (-1);
	return (retswap);
}

static char				*ft_truncate(char **file, int length)
{
	char	*save;

	save = *file;
	if (!(*file = ft_strdup(&file[0][length + 1])))
		return (NULL);
	if (!**file)
		ft_strdel(file);
	free(save);
	return (*file);
}

static char				*ft_mallocline(char **line, char **file)
{
	char	*parseur;
	int		length;

	if ((parseur = ft_strchr(*file, '\n')))
	{
		length = (parseur - *file);
		if (!(*line = ft_strsub(*file, 0, length)))
			return (NULL);
		ft_truncate(file, length);
		return (*line);
	}
	else
	{
		if (!**file)
		{
			*line = malloc(1);
			**line = '\0';
			ft_strdel(file);
		}
		if (!(*line = ft_strdup(*file)))
			return (NULL);
		ft_strdel(file);
		return (*line);
	}
}

int						get_next_line(const int fd, char **line)
{
	static char		*file;
	int				i;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	if (file == NULL || (file && !(ft_strchr(file, '\n'))))
	{
		if (file && *file && ft_strchr(file, '\n'))
		{
			if (!(ft_mallocline(line, &file)))
				return (-1);
			return (1);
		}
		if (!(i = ft_readfile(fd, &file)) || i == -1)
		{
			if (!file || !*file)
				return (i);
		}
	}
	if (!(ft_mallocline(line, &file)))
		return (-1);
	return (1);
}
