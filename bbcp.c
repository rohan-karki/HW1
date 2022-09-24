#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <sys/stat.h>

/* The below defined buffer size specifies the max file size that can be copied */
#ifndef BUF_SIZE
#define BUF_SIZE 12678376298
#endif

/* The below defined limit specifies the length assigned to a file name */
#ifndef BUF_LIMIT
#define BUF_LIMIT 1024
#endif

/*
* This code copies a file onto the specified path
* The program requires two arguments, --source-- and --destination-- 
* The destination can either be a file or a directory
*/

int main(int argc, char** argv)
{
	int file_in, file_out;
	char file_buff[BUF_SIZE];
	ssize_t num;
	struct stat buff;

	if(argc == 3)
	{
		exit(0);
	}


	if (strcmp(argv[1], argv[2]) == 0)
	{
		fprintf(stderr, "The source file is same as the destination file \n");

		exit(1);
	}
/*---------------------------------------------------------------------------------------------------------------------------------*/
	file_out = open(argv[2], O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if(file_out != 0)
	{
		fprintf(stderr, "Error - File cannot be accessed: %s \n", argv[2]);
		exit(1);
	}

/*The above code snippet checks whether the specified file is readable/writable or not*/
/*---------------------------------------------------------------------------------------------------------------------------------*/

	while((num = read(file_in, file_buff, BUF_SIZE)) > 0)
	{
		if(write(file_out, file_buff, num) != num)
		{
			exit(1);
		}
	}

/*The above code snippet will read the input file and copy the file*/
/*----------------------------------------------------------------------------------------------------------------------------------*/

	if(close(file_out) != 0)
	{
		exit(1);
	}

	if(close(file_in) != 0)
	{
		exit(1);
	}
/*The above code snippet checks whether the respective opened file is closed after the copy operation*/
/*-----------------------------------------------------------------------------------------------------------------------------------*/

	if(S_ISDIR(buff.st_mode))
	{
		strcat(argv[2], "/");
		strcat(argv[2], basename(strdup(argv[1])));
	}
}