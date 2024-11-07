#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int balance = 1000;
void *withdraw(void *param);
int main() {
pthread_t officer[4];
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_attr_init(&attr);
int cash = 1000;
pthread_create(&officer[0], &attr,withdraw, &cash);
pthread_create(&officer[1], &attr,withdraw, &cash);
pthread_create(&officer[2], &attr,withdraw, &cash);
pthread_create(&officer[3], &attr,withdraw, &cash);
for(int i=0;i<4;i++) {
pthread_join(officer[i], NULL);
}
printf("Final balance: %d\n", balance);
exit(EXIT_SUCCESS);
}
void *withdraw(void *param) {
int amount = *(int *)param;
if(balance>=amount) {printf("Withdrawn amount: %d is successfully. Current
Balance is: %d\n", amount,balance-amount);
balance -= amount;
}else {
printf("Insufficient balance\n");
}
}
