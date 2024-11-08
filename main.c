#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd1 = open("file1.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_RDONLY);

	printf("%s \n", get_next_line(fd1));

	close(fd1);
	close(fd2);
	return 0;
}