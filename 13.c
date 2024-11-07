#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) is replacing its memory image with a new program.\n", getpid());
        execlp("/bin/ls", "ls", "-l", NULL);

        // If execlp() fails
        perror("execlp failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        printf("Parent process (PID: %d) is waiting for the child process to complete.\n", getpid());
        wait(NULL);
        printf("Child process has completed.\n");
    } else {
        // Fork failed
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
