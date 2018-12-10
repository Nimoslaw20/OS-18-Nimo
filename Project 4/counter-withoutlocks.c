#include <stdio.h>
#include <pthread.h>

typedef struct __counter_t {
    int value; 
}

counter_t;

counter_t init(counter_t c) {
    c.value = 0;
    return c;
}

void *increment(counter_t *c) {
    c->value++;
}

void decrement(counter_t *c) {
    c->value--;
}

int get(counter_t *c) {
    return c->value;
}


void *counting (void *arg) {
    int i;
    int end = 1000;
    counter_t *count = (counter_t* ) arg;
    for(i=0;i<end; i++){

        increment(count);
    }
    
    return NULL;
}
    


int main (){
    //Initializing counter.
    counter_t Cnt;
    Cnt= init(Cnt);
    
    //Creating threads for execution
    pthread_t p1, p2, p3;  
    //...
    printf("Starting value of (counter = %d)\n", get(&Cnt));
    pthread_create(&p1, NULL, counting, &Cnt);
    pthread_create(&p2, NULL, counting, &Cnt);
    pthread_create(&p3, NULL, counting, &Cnt);
    //...
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);
  //...
    printf("Closing value (counter = %d)\n", get(&Cnt));
    return 0;
    
}