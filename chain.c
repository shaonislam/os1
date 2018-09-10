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



void processes(int n, pid_t childpid)
{
        int i;
        for (i = 1; i < n; i++)  
        {        
		if ((childpid = fork()))
                        break;                                
        	fprintf(stderr, "i:%d 	process ID:%ld 	parent ID:%ld 	child ID:%ld\n",i, (long)getpid(), (long)getppid(), (long)childpid);
	}
	
}
    

int main (int argc, char *argv[]) 
{
	pid_t childpid = 0;
	int option;

	if (argc != 2)
        {
                /* check for valid number of command-line arguments */
                fprintf(stderr, "Usage: %s processes\n", argv[0]);
        }


	while((option = getopt(argc, argv, "hpn:")) != -1)
	{
		switch (option)
			{
			case 'h':
				fprintf(stderr, "Help Message: Valid inputs are as followed\n");
				fprintf(stderr, "-n x: x being an integer\n");
				fprintf(stderr, "-h: displays help message\n");
				fprintf(stderr, "-p: generates a test error message\n");
				exit(1);	
			case 'p':
				fprintf(stderr, "%s ", argv[0]);
				perror("Error: Detailed error message");
				break;
			case 'n':
                                fprintf(stderr, "You have selected N\n");
				processes(atoi(optarg), childpid);
                                break;
			case '?':
				fprintf(stderr, "Error\n");
				break;
			}
	}



	return 0;
}
	



