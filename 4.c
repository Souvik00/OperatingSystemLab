/*
  4.Write a C program to create a main process named ‘parent_process’ having 3child processes without any grandchildren processes. 
  Child Processes’ names are child_1, child_2, child_3. Trace the position in the process tree.
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>
int main()
{
   pid_t pid1, pid2, pid3;
   int a = 10, b = 5;
   prctl(PR_SET_NAME, "Pareent", 0, 0, 0);
   printf("Parent process (PID: %d)\n", getpid());
   pid1 = fork();
   if (pid1 == 0)
   {
      prctl(PR_SET_NAME, "child_1", 0, 0, 0);
      printf("Child 1 (PID: %d)\n", getpid());
      return 0;
   }
   wait(NULL);
   pid2 = fork();
   if (pid2 == 0)
   {
      prctl(PR_SET_NAME, "child_2", 0, 0, 0);
      printf("Child 2 (PID: %d)\n", getpid());
      return 0;
   }
   wait(NULL);
   pid3 = fork();
   if (pid3 == 0)
   {
      prctl(PR_SET_NAME, "child_3", 0, 0, 0);
      printf("Child 3 (PID: %d)\n", getpid());
      return 0;
   }
   wait(NULL);
   printf("Parent process ends\n");
   sleep(100);
   return 0;
}

