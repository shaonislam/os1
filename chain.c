/*
Shaon Islam
CS 4760: Operating Systems
Project 1
September 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <getopt.h>


/* User getopt: 
	 -n x:
	 -h: display help message indicating type of input needed
	 -p: uses perror to generate a test error message as describes in task4
*/


int main (int argc, char *argv[]) 
{
	pid_t childpid = 0;
	int i, n; 	

	/* Attempt 1 at get opt */
	/* optopt: when getopt stumbles on an unknown option char or with a missing arg */

	int option;

	while((option = getopt(argc, argv, "hpn")) != -1)
	{
		switch (option)
			{
			case 'h':
				fprintf(stderr, "You have selected H");
				break;	
			case 'p':
				fprintf(stderr, "You have selected P");
				break;
			case 'n':
                                fprintf(stderr, "You have selected N");
                                break;
			case '?':
				fprintf(stderr, "Error");
				break;
			}
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


