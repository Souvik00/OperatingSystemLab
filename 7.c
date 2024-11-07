#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<signal.h>
int isSignalReceived = 0;
void signalHandler(int signum) {
printf("Thread_%ld receive Signal: %d\n",pthread_self(),signum);
isSignalReceived = 1;
}
void* function1(void* param) {
pthread_t* thread = (pthread_t*)param;
printf("Hi. This is Thread_%ld\n", pthread_self());
printf("Thread 1 will send a signal to thread_%ld\n",*thread);
sleep(2);
printf("Thread 1 is sending signal to Thread 2\n");
pthread_kill(*thread,SIGUSR1);
printf("Signal sent.\n");
}
void *function2(void* param) {
sleep(1);
printf("This is Thread_%ld. Waiting for signal.\n",pthread_self());
signal(SIGUSR1,signalHandler);
while(!isSignalReceived);
}
int main() {
pthread_t t1,t2;
pthread_create(&t1,NULL,function1,&t2);
pthread_create(&t2,NULL,function2,NULL);
pthread_join(t1,NULL);pthread_join(t2,NULL);
return 0;
}
