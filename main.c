
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd1 = open("txt2.txt", O_RDWR);
	 int fd2 = open("txt.txt", O_RDWR);
	
	printf("%s", get_next_line(fd1));
    printf("%s", get_next_line(fd2));
 	printf("%s", get_next_line(fd1));
 	printf("%s", get_next_line(fd2));
 	printf("%s", get_next_line(fd1));
 }