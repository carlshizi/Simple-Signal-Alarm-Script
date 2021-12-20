/*
 *      _  ______  _          __          ______  _      ______ 
 *     | |/ / __ \| |        /\ \        / / __ \| |    |  ____|
 *     | ' / |  | | |       /  \ \  /\  / / |  | | |    | |__   
 *     |  <| |  | | |      / /\ \ \/  \/ /| |  | | |    |  __|  
 *     | . \ |__| | |____ / ____ \  /\  / | |__| | |____| |____ 
 *     |_|\_\____/|______/_/    \_\/  \/   \____/|______|______|
 *                                                              
 *                                                              
 *
 *	*************** SIGNAL ALARM SCRIPT ***************
 *	The program uses fork,  sleep,  and  signal to
 *	simulate an alarm  that goes off after  5 secs.
 *	***************************************************
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define SEC 5

void msg(int); // signal handler message for parent proccess

int main()
{
    signal(SIGALRM, msg);
    printf("Alarm app starting\n");

    // a new child process is forked if zero
    if (fork() == 0)
    {
        printf("Waiting for alarm to go off...\n\n");
        sleep(SEC);
        kill(getppid(), SIGALRM);
        exit(0);
    }

    wait(NULL);
    printf("Done.\n");
}

void msg(int signal){
	printf("Ding!\n");
    }
