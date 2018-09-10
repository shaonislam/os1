
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/* TASK 5 */
/* _____program 3.1 with loop around fprintf executing k times_____*/
/* sleep(m) inside loop after fprintf */
/* passing n, k, and m on command like */
/* Observe results */

int main (int argc, char *argv[]) 
{
 	
	pid_t childpid = 0;
 
	int i, n, k, j, m;

	/* NEW: k is added to find max loops 
	and j is in incrementer for the loop 
	and m is the amount time to sleep */	

	 if (argc != 4)
	{ 	/* check for valid number of command-line arguments */
 		fprintf(stderr, "Usage: %s processes\n", argv[0]);
		fprintf(stderr, "Usage: K: %s, M: %s, N: %s\n", argv[2], argv[3], argv[1]);
 		return 1;
 	}



 	n = atoi(argv[1]);
	k = atoi(argv[2]);
	m = atoi(argv[3]);
 
	for (i = 0; i < n; i++)
 	{	
		if (childpid = fork())
 		break;
	}
	
	for (j = 0; j < k; j++)
 		{	
			fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);
			sleep(m);
		}

	
 	return 0;
}
