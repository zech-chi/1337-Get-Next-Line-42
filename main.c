#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>	
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
	int fd = open("/Users/zech-chi/Desktop/get_next_line/testfiles/file.txt", O_RDONLY);
	char	*line;
	printf("fd = %d\n", fd);
	for (int i = 0; i < 5; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line)
			free(line);
	}
	return (0);
}

