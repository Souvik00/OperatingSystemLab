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
pid_t pid = fork();
if(pid<0) {
printf("Fork() Error\n");
exit(1);
}
if(pid==0) {
printf("Child process is created from thread_%d.\nChild
Process is running\n",num);
sleep(1);
printf("Child Process is exiting\n");exit(0);
}
else {
printf("Parent Process is exiting.\n");
}
}
sleep(3);
printf("Thread_%d is exiting.\n", num);
}
