#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <signal.h>

static void sighandler(int signo){
	if(signo==SIGSEGV){
    printf("hello \n");
		printf("What abt faulty programs\n");
  }
	else if (signo==SIGUSR1){
		printf("What you want from me?!?\n");
	} //this function gives an error...ignore it(?)
}

//THE PUSH FINALLY WORKED


int main(){
	signal(SIGUSR1, sighandler);
	signal(SIGSEGV, sighandler);

	while(1){
		printf( "hello i am %s\n", getpid() );
		sleep(1);
	}
	return 0;
}
