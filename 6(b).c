#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
void *function(void *param);
int main() {
pthread_t thread[3];
int id[3];
for(int i=0;i<3;i++) {
id[i]=i+1;
pthread_create(&thread[i], NULL, function, (void *)&id[i]);
}
for(int i=0;i<3;i++) {
pthread_join(thread[i], NULL);
}
printf("Main Thread is exiting.\n");
exit(0);
}
void *function(void *param) {
int num = *((int *)param);
printf("Thread_%d start running\n", num);
if(num==1) {
execlp("./hello","hello",NULL);
}
sleep(3);
printf("Thread_%d is exiting.\n", num);
}
