2.An orphan process is created when its parent process terminates before the child process.
Code:
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>
int main()
{
   pid_t pid = fork();
   if (pid > 0)
   {
      prctl(PR_SET_NAME, "Pareent", 0, 0, 0);
      printf("Parent process is terminated.\n");
      exit(0);
   }
   else if (pid == 0)
   {
      prctl(PR_SET_NAME, "1_Orphan", 0, 0, 0);
      sleep(50);
      printf("Orphan child process running.\n");
   }
  sleep(50);
   return 0;
}
