/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:21:00 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/05 15:40:38 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdio.h>

static void file1_gnl() {
	int		fildes;
	char	*line;
	int		i;

	// first, try reading from file
	fildes = open("test.txt", O_RDONLY);
	line = get_next_line(fildes);
	i = 0;
	while (line) {
		printf("Linea %i: %s", i++, line);
		free(line);
		line = get_next_line(fildes);
	}
	free(line);
}

static void stdio_gnl() {
	// try reading from stdio
	char *line = get_next_line(0);
	printf("stdin: %s", line);
	free(line);
}

int main() {
	file1_gnl();
	stdio_gnl();
	// TODO implement checks for
	//  empty file
	//  invalid fd
	return 0;
}
