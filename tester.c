/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:31:58 by nfararan          #+#    #+#             */
/*   Updated: 2024/04/04 14:49:10 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#ifndef RED
# define RED "\e[0;31m"
#endif
#ifndef BLUE
# define BLUE "\e[0;34m"
#endif
#ifndef END_COLOR
# define END_COLOR "\e[0m"
#endif

static void	print_error(const char *err)
{
	fprintf(stderr, RED"%s"END_COLOR, err);
	exit(EXIT_FAILURE);
}

static void	print_line(int num, char *line)
{
	printf(BLUE"%3d: "END_COLOR"%s", num, line);
}

int	main(int ac, char **av)
{
	char	*file_path;
	int		fd;
	char	*line;
	int		num;

	if (ac != 2)
		print_error("Put one file as argument\n");
	file_path = av[1];
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		print_error("Error on opening file\n");
	num = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			print_error("Error on get_next_line\n");
		print_line(num++, line);
		free(line);
	}
	close(fd);
}
