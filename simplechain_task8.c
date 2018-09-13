
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/* _____program 3.1 with nchars being inputted and put into mybuff array_____*/


int main (int argc, char *argv[]) 
{
 	
	pid_t childpid = 0;
 	int i, j, n, nchars;
	
	char* mybuf;

	 if (argc != 3)
	{ 	
		/* check for valid number of command-line arguments */

 		fprintf(stderr, "Usage: %s processes\n", argv[0]);
 		return 1;
 	}


 	n = atoi(argv[1]);
	nchars = atoi(argv[2]);
	mybuf = malloc(sizeof(char) * (nchars + 1)); 

	for (i = 1; i < n; i++)
 		if (childpid = fork())
 		break;


	for(j = 0; j < nchars; j++)
	{
		scanf(" %c", &mybuf[j]);
	}


	mybuf[nchars] =	'\0';


	fprintf(stderr, "Process ID: %ld  Mybuf: %s\n", (long)getpid(), mybuf);

 	/*fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);*/

	free(mybuf);
 	return 0;

}
