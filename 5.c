#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include<string.h>
int main(int argc, char *argv[]) {
printf("I am the Parent process (PID: %d)\n",
getpid());
int n = atoi(argv[1]);
printf("Number of child processes to be created:
%d\n", n);
for(int i=1;i<=n;i++) {
pid_t pid = fork();
if(pid<0) {
printf("error.");
exit(1);
}
else if(pid==0) {
char cmd[]="./gen ";
strcat(cmd,argv[i+1]);
strcat(cmd," > ");
strcat(cmd,argv[i+1]);
strcat(cmd,".c");
//printf("%s\n",cmd);
system(cmd);
char cmd2[]="gcc ";
strcat(cmd2,argv[i+1]);
strcat(cmd2,".c -o ");
strcat(cmd2,argv[i+1]);
system(cmd2);
//printf("%s\n",cmd2);
char fl[] = "./";
strcat(fl,argv[i+1]);
//printf("%s\n",fl);execlp(fl,argv[i+1],NULL);
exit(0);
}
else{
// this parent process does noting.
}
}
for(int i=0;i<3;i++) {
wait(NULL);
}
printf("Parent process (PID: %d) exiting\n",
getpid());
return 0;
return 0;
}
