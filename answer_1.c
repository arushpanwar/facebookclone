#include<stdio.h>
#include<pthread.h>
void *thread_function(void *args);
int main()
{
    pthread_t th;
    pthread_create(&th, NULL, thread_function, NULL);
    void *ps;
    pthread_join(th, &ps);
    printf("%s\n", (char *)ps);
    return 0;
}
void *thread_function(void *args)
{
    printf("Thread created with id %ld\n", pthread_self());
    pthread_exit("Thread terminated");
}