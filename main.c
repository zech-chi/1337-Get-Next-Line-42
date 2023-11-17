#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>	


int main() {

	int fd = open("maze.txt", O_RDONLY);
	char *line;

	for (int i = 0; i < 50; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	return (0);
}