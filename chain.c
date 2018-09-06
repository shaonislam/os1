#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>



/* User getopt: 
	 -n x:
	 -h: display help message indicating type of input needed
	 -p: uses perror to generate a test error message as describes in task4
*/






int main (int argc, char *argv[]) 
{
	pid_t childpid = 0;
	int i, n; 	
	int helpflag;
	int errorflag;
	char option;

	/* Attempt 1 at get opt */
	/* optopt: when getopt stumbles on an unknown option char or with a missing arg */


	option = getopt (argc, argv, "h");

	while(option != -1)
	{
		switch (option)
			{
			case 'h':
				helpflag = 1;
				break;	
			case '?':
				errorflag = 1;
				break;

			}
	}


	if (helpflag == 1)
	{
		fprintf(stderr, "HELP MESSAGE");
	}

	if (errorflag == 1)
        {
                fprintf(stderr, "ERROR  MESSAGE");
        }


	if (argc != 2)
	{ 
		/* check for valid number of command-line arguments */
 		fprintf(stderr, "Usage: %s processes\n", argv[0]);
 		return 1;
 	}

 	n = atoi(argv[1]);
 
	for (i = 1; i < n; i++)
		if ((childpid = fork()))
 			break;
 
	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
 	i, (long)getpid(), (long)getppid(), (long)childpid);
 	return 0;
}


