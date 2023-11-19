#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>	
#include <string.h>


int main() {
	int fd = open("/Users/zech-chi/Desktop/get_next_line/testfiles/maze.txt", O_RDONLY);
	//char	*line;
	//for (int i = 0; i < 2; i++)
	//{
	//	line = get_next_line(fd);
	//	printf("%s", line);
	//	if (line)
	//		free(line);
	//}
	int j = read(fd, buff, 0);
	printf("%d", j);
	return (0);
}