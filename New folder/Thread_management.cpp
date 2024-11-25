//Thread management
#include<bits/stdc++.h>
void* threadfunction(void* arg){
    printf("Thread ID: %ld\n", pthread_self());
    return NULL;
}

int main(){
    pthread_t thread1, thread2;

    pthread_create(&thread1 , NULL, threadfunction, NULL);
    pthread_create(&thread2, NULL, threadfunction, NULL);


    //pthread_join(thread1, NULL); and pthread_join(thread2, NULL);
    // ensure that the main thread waits for both thread1 and thread2 to finish execution before the program terminates.
    // This prevents the main thread from exiting prematurely, potentially before the other threads complete their work.

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);




}


