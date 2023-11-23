/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:53:16 by maruiz-p          #+#    #+#             */
/*   Updated: 2023/11/23 17:13:15 by maruiz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*readline(int fd, char *txt)
{
	char	*aux;
	int		counter;

	counter = 1;
	aux = ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	if (!aux)
		return (free(txt), txt = NULL, NULL);
	while (counter != 0 && !ft_strchr_gnl(aux, '\n'))
	{
		counter = read(fd, aux, BUFFER_SIZE);
		if (counter < 0)
			return (free(txt), txt = NULL, free(aux), aux = NULL, NULL);
		aux[counter] = '\0';
		txt = ft_strjoin_gnl(txt, aux);
		if (!txt)
			return (free(txt), txt = NULL, free(aux), aux = NULL, NULL);
	}
	return (free(aux), aux = NULL, txt);
}

char	*nextline(char *txt)
{
	char	*aux;
	int		counter;

	counter = 0;
	if (txt[counter] == '\0')
		return (NULL);
	while (txt[counter] != '\0' && txt[counter] != '\n')
		counter++;
	aux = ft_calloc_gnl((counter + 1 + (txt[counter] == '\n')), sizeof(char));
	if (!aux)
		return (NULL);
	counter = 0;
	while (txt[counter] != '\0' && txt[counter] != '\n')
	{
		aux[counter] = txt[counter];
		counter++;
	}
	if (txt[counter] == '\n' && txt[counter] != '\0')
		aux[counter++] = '\n';
	aux[counter] = '\0';
	return (aux);
}

char	*cleanbuffer(char *txt)
{
	char	*result;
	int		c1;
	int		c2;

	c1 = 0;
	while (txt[c1] != '\0' && txt[c1] != '\n')
		c1++;
	if (txt[c1] == '\0')
		return (free(txt), txt = NULL, NULL);
	c2 = 0;
	result = ft_calloc_gnl((ft_strlen_gnl(txt) - c1 + 1), sizeof(char));
	if (!result)
		return (free(txt), txt = NULL, NULL);
	c2 = 0;
	while (txt[++c1] != '\0')
		result[c2++] = txt[c1];
	result[c2] = '\0';
	return (free(txt), txt = NULL, result);
}

char	*get_next_line(int fd)
{
	static char	*txt[1024];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (txt[fd] != NULL)
		{
			free(txt[fd]);
			txt[fd] = NULL;
		}
		return (NULL);
	}
	txt[fd] = readline(fd, txt[fd]);
	if (!txt[fd])
		return (free(txt[fd]), txt[fd] = NULL, NULL);
	result = nextline(txt[fd]);
	if (!result)
		return (free(txt[fd]), txt[fd] = NULL, NULL);
	txt[fd] = cleanbuffer(txt[fd]);
	if (!txt[fd])
		return (free(txt[fd]), txt[fd] = NULL, result);
	return (result);
}
/* 
#include "get_next_line_bonus.h"

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		tester;
	char	*written_line;

	tester = open("test.txt", O_RDONLY);
	written_line = get_next_line(tester);
	while (written_line != NULL)
	{
		printf("%s", written_line);
		written_line = get_next_line(tester);
	}
	printf("\n");
	close(tester);
	free(written_line);
} */