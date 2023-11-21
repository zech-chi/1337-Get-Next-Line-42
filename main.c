#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>	
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main() {
	int fd = open("/Users/zech-chi/Desktop/get_next_line/testfiles/file.txt", O_RDONLY);
	char	*line;
	printf("fd = %d\n", fd);
	dup2(fd, 0);
	line = get_next_line(fd);
	printf("%s", line);
	if (line)
		free(line);
	

	line = get_next_line(fd);
	printf("%s", line);
	if (line)
		free(line);

	printf("open_max = %d\n", OPEN_MAX);
	return (0);
}

