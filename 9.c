#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
double average;
int max_val;
int min_val;
typedef struct {
int *numbers;
int count;
} thread_data;
void *calculate_average(void *arg) {
thread_data *data = (thread_data *)arg;
int sum = 0;
for (int i = 0; i < data->count; i++) {
sum += data->numbers[i];
}
average = (double)sum / data->count;
pthread_exit(NULL);
}
void *calculate_maximum(void *arg) {
thread_data *data = (thread_data *)arg;
max_val = data->numbers[0];
for (int i = 1; i < data->count; i++) {
if (data->numbers[i] > max_val) {
max_val = data->numbers[i];
}
}
pthread_exit(NULL);
}
void *calculate_minimum(void *arg) {
thread_data *data = (thread_data *)arg;
min_val = data->numbers[0];
for (int i = 1; i < data->count; i++) {
if (data->numbers[i] < min_val) {
min_val = data->numbers[i];
}
}
pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
if (argc < 2) {
printf("Please pass the argument as .%s num1 num2 num3 ...\n",
argv[0]);
return 1;
}
int count = argc - 1;
int *numbers = malloc(count * sizeof(int));
for (int i = 0; i < count; i++) {
numbers[i] = atoi(argv[i + 1]);
}
thread_data data = { numbers, count };
pthread_t threads[3];
pthread_create(&threads[0], NULL, calculate_average, (void *)&data);
pthread_create(&threads[1], NULL, calculate_maximum, (void *)&data);
pthread_create(&threads[2], NULL, calculate_minimum, (void *)&data);
for (int i = 0; i < 3; i++) {
pthread_join(threads[i], NULL);
}
printf("The average value is %f\n", average);
printf("The minimum value is %d\n", min_val);
printf("The maximum value is %d\n", max_val);
free(numbers);
return 0;
}
