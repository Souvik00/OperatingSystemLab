#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_WATER_LEVEL 100
#define MIN_WATER_LEVEL 20

int water_level = 50;
bool motor_on = false;
pthread_mutex_t lock;

void* sensor_thread(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        water_level -= 5;
        printf("Sensor: Current water level = %d\n", water_level);
        if (water_level < MIN_WATER_LEVEL) {
            printf("Sensor: Water level low! Turning motor ON.\n");
            motor_on = true;
        }
        pthread_mutex_unlock(&lock);

        sleep(1);
    }

}

void* motor_thread(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);

        if (motor_on) {
            water_level += 10;
            printf("Motor: Filling... Current water level = %d\n", water_level);
            if (water_level >= MAX_WATER_LEVEL) {
                printf("Motor: Tank full! Turning motor OFF.\n");
                motor_on = false;
            }
        }
        pthread_mutex_unlock(&lock);
        sleep(1); 
        
    }
   
}

int main() {
    pthread_t sensor, motor;

    pthread_mutex_init(&lock, NULL);
    
    pthread_create(&sensor, NULL, sensor_thread, NULL);
    pthread_create(&motor, NULL, motor_thread, NULL);

    pthread_join(sensor, NULL);
    pthread_join(motor, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}

