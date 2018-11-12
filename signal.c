#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sighandler(int signo){
	if(signo==SIGSEGV){
    printf("SIGINT intercepted \n");
		exit(0);
  }
	else if (signo==SIGUSR1){
		printf("parent pid: %d\n", getppid());
	} //this function gives an error...ignore it(?)
}

int main(){
	signal(SIGUSR1, sighandler);
	signal(SIGSEGV, sighandler);

	while(1){
		printf( "hello i am %d\n", getpid() );
		sleep(1);
	}
	return 0;
}
