/*
3.Write a program to create a zombie process.
*/ 
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
      printf("Parent process (PID: %d) sleeping.\n", getpid());
      sleep(10);
      wait(NULL);
      printf("Zombie Process\n");
   }
   else if (pid == 0)
   {
      prctl(PR_SET_NAME, "Zombie", 0, 0, 0);
      printf("Child process (PID: %d) is terminating.\n", getpid());
      exit(0);
   }

   return 0;
}
