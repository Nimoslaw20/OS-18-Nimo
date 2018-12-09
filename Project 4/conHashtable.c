//Hashtable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

//Thread and lock implementation
pthread_t thread1, thread2;
pthread_mutex_t mutexInsert = PTHREAD_MUTEX_INITIALIZER; 
pthread_mutex_t mutexDelete = PTHREAD_MUTEX_INITIALIZER; 

#define SIZE 10

//Initializing data and key for Item
struct Item {
   int data;  
   int key;   
};

struct Item* hashArray[SIZE]; // hash array size
struct Item* dummyItem; //dummy data after deleting
struct Item* item;  
struct Item* args;

//hashing function for getting the index
int hashCode(int key) {
   return key % SIZE;
}


struct Item *search(int key) {
   //get the hash
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
      if(hashArray[hashIndex]->key == key)
          return hashArray[hashIndex];
      
	  //go to next cell
      ++hashIndex;
      
      
      //wrap around the table
      hashIndex %= SIZE;
   }

   return NULL;
}

//insert function
void insert(int key,int data) {
    pthread_mutex_lock(&mutexInsert);
	struct Item *item = (struct Item*) malloc(sizeof(struct Item));
	item->data = data;
	item->key = key;

   //get the hash
    int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      
      ++hashIndex; //go to next cell

      
      hashIndex %= SIZE;  //wrap around the table
    }
    hashArray[hashIndex] = item;
    printf("%Data and key: \n",data,key);

    pthread_mutex_unlock(&mutexInsert); //unlocking the critical section
}

//Delete function
struct Item* delete1(struct Item* item) {
   pthread_mutex_lock(&mutexDelete);//locking the critical section
   int key = item->key;
   //get the hash
   int hashIndex = hashCode(key);
   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
      if(hashArray[hashIndex]->key == key) {
         struct Item* temp = hashArray[hashIndex];
         //assign a dummy item at deleted position
         printf(" (%d,%d) Item deleted \n",hashArray[hashIndex]->key,hashArray[hashIndex]->data);
         hashArray[hashIndex] = dummyItem;
         return temp;
      }
      
      ++hashIndex; //go to next cell

      hashIndex %= SIZE; //wrap around the table
   }
   printf("Item no deleted \n");
   pthread_mutex_unlock(&mutexDelete); //unlocking the critical section
   return NULL;
}

//Displaying of the table and results function
void display() {
   int i = 0;
   printf("HashTable: {");
   for(i = 0; i<SIZE; i++) {
      if(hashArray[i] != NULL)
         printf("(%d,%d)",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" (NONE)");
   }
    printf("}\n");
   printf("\n");
}
 
