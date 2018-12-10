#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

typedef struct __counter_t {
    int value;
    pthread_mutex_t lock;
}

counter_t;

counter_t init(counter_t c) {
    c.value = 0;
    pthread_mutex_init(&c.lock, NULL);
    return c;
    
}

void *increment(counter_t *c) {
    pthread_mutex_lock(&c->lock);   
    c->value++;
    pthread_mutex_unlock(&c->lock);
}

void decrement(counter_t *c) {
    pthread_mutex_lock(&c->lock);
    c->value--;
    pthread_mutex_unlock(&c->lock);
}

int get(counter_t *c) {
    pthread_mutex_lock(&c->lock);
    int rc = c->value;
    pthread_mutex_unlock(&c->lock);
    return rc;
}


void *counting (void *arg) {
    int i;
    int end = 1000;
    counter_t *count = (counter_t *) arg;
    for(i=0;i<end; i++){
        increment(count);
    }
    
    return NULL;
}
    


int main (){
    //Initializing counter
    counter_t Cnt;
    Cnt= init(Cnt);
    
   //Creating threads for execution
    pthread_t p1, p2, p3;
    //..
    printf("Starting value of (counter = %d)\n", get(&Cnt));
    pthread_create(&p1, NULL, counting, &Cnt);
    pthread_create(&p2, NULL, counting, &Cnt);
    pthread_create(&p3, NULL, counting, &Cnt);
    //..
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
    //..
    printf("Closing value (counter = %d)\n", get(&Cnt));
    return 0;
    
}