
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/* _____program 3.1 with a sleep(10); after final fprintf_____*/


int main (int argc, char *argv[]) 
{
 	
	pid_t childpid = 0;
 	int i, n;

	 if (argc != 2)
	{ 	/* check for valid number of command-line arguments */
 		fprintf(stderr, "Usage: %s processes\n", argv[0]);
 		return 1;
 	}

 	n = atoi(argv[1]);
 
	for (i = 1; i < n; i++)
 		if (childpid = fork())
 		break;
 	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
	sleep(10);
 	return 0;
}