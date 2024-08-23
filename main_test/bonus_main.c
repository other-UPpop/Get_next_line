#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

#define NUMBER_FILE 3

int main(void)
{
	int 	fd[NUMBER_FILE];
	char	*line;
//	size_t	i = 0, j = 0;

	fd[0] = open("1.text", O_RDONLY);
	fd[1] = open("2.text", O_RDONLY);
	fd[2] = open("3.text", O_RDONLY);

	if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0)
	{
		printf("fd error");
		return (1);
	}
	line = get_next_line(fd[0]);
	if (line != NULL)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd[1]);
		if (line != NULL)
		{
			printf("%s", line);
			free (line);
			line = get_next_line(fd[2]);
			if (line != NULL)
			{
				printf("%s", line);
				free (line);
			}
		}
	}
	line = get_next_line(fd[0]);
	if (line != NULL)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd[1]);
		if (line != NULL)
		{
			printf("%s", line);
			free (line);
			line = get_next_line(fd[2]);
			if (line != NULL)
			{
				printf("%s", line);
				free (line);
			}
		}
	}
	close (fd[0]);
	close (fd[1]);
	close (fd[2]);
	return (0);
}
//	while(i < NUMBER_FILE)
//	{
//		printf("file number %ld", i);
//		while ((line = get_next_line(fd[i])) != NULL)
//		{
//			printf("%s", line);
//			free (line);
//		}
//		printf("\n");
//		++i;
//	}
//	close (fd[0]);
//	close (fd[1]);
//	close (fd[2]);
//	return (0);
//}
//	}
//	line = get_next_line(fd[0]);
//	line = get_next_line(fd[0]);
//	line = get_next_line(fd[0]);
////	while(i < NUMBER_FILE)
////	{
////		printf("file number %ld", i);
////		while ((line = get_next_line(fd[i])) != NULL)
////		{
////			printf("%s", line);
////			free (line);
////		}
////		printf("\n");
////		++i;
////	}
//	close (fd[0]);
//	close (fd[1]);
//	close (fd[2]);
//	return (0);
//}
