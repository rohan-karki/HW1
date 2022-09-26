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
#define BUF_SIZE 1024
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
	char source_file[1], target_file[1];
	char file_buff[BUF_SIZE];
	ssize_t num;
	struct stat buff;

	if(argc != 3)
	{
		fprintf(stderr, "Usage: ./<binary> <source-file> <target-file>");
		exit(EXIT_FAILURE);
	}

	if(strcmp(argv[1], argv[2]) == 0)
	{
		fprintf(stderr, "The source file is same as the destination file \n");

		exit(EXIT_FAILURE);
	}

/*The above code checks whether the entered file is same as the destination file*/
/*---------------------------------------------------------------------------------------------------------------------------------*/

	stat(argv[1], &buff);

	if(S_ISREG(buff.st_mode)) 
	{

	} 
	else 
	{
		fprintf(stderr, "%s is not a valid file \n", argv[1]);
		exit(EXIT_FAILURE);
	}
/*The above code snippet checks for the validity of the file taken as input
/*-----------------------------------------------------------------------------------------------------------------------------------*/

	source_file[0] = open(argv[1], O_RDONLY);

	if(source_file[0] == -1)
	{
		fprintf(stderr, "Error - File cannot be opened: %s \n", argv[1]);
		exit(EXIT_FAILURE);
	}

/*Here the source file is accepted as an argument with read only permissions and then checked with a if condition whether the file can be opened or not.
/*-----------------------------------------------------------------------------------------------------------------------------------*/
	stat(argv[2], &buff);

	if(S_ISDIR(buff.st_mode))
	{
		strcat(argv[2], "/");
		strcat(argv[2], basename(strdup(argv[1])));
	}

/*---------------------------------------------------------------------------------------------------------------------------------*/

	target_file[0] = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

	if(target_file[0] == -1)
	{
		fprintf(stderr, "Error - File cannot be accessed: %s \n", argv[2]);
		exit(EXIT_FAILURE);
	}

/*The above code snippet checks whether the specified file is readable/writable or not*/
/*---------------------------------------------------------------------------------------------------------------------------------*/

	while((num = read(source_file[0], file_buff, BUF_SIZE)) > 0 )
	{
		if(write(target_file[0], file_buff, num) != num)
		{
			exit(EXIT_FAILURE);
		}
	
	}

/*The above while loop will read the input file, along with the file buffer size and copy the file, keeping the buffer constant*/
/*----------------------------------------------------------------------------------------------------------------------------------*/

	if(close(target_file[0]) != 0)
	{
		exit(EXIT_FAILURE);
	}

	if(close(source_file[0]) != 0)
	{
		exit(EXIT_FAILURE);
	}


/*This part checks whether the respective opened file is closed after the copy operation and returns an error if the closing operation was not performed successfully*/

	return(0);
}