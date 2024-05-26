# OperatingSystemLab
##1.Write a C program to create a main process named ‘parent_process’ having 3
child processes without any grandchildren processes.
Trace parent and child processes in the process tree.
Show that child processes are doing addition, subtraction and multiplication on
two variables initialized in the parent_process.

##2.Write a program to create an orphan process.

##3.Write a program to create a zombie process.

##4.Write a C program to create a main process named ‘parent_process’ having 3
child processes without any grandchildren processes. Child Processes’ names
are child_1, child_2, child_3. Trace the position in the process tree.

##5.Write a C program to create a main process named ‘parent_process’ having ‘n’
child processes without any grandchildren processes. Child Processes’ names
are child_1, child_2, child_3,......., child_n. Trace the position in the process
tree. Number of child processes (n) and name of child processes will be given
in the CLI of Linux based systems.
Example:
$ ./parent_process 3 child_1 child_2 child_3
Hint: fork, exec, fopen, system
