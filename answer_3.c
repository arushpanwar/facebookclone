#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread_function(void *args);
int main()
{
    pthread_t th;
    while(1)
    {
        pthread_create(&th, NULL, thread_function, NULL);
        sleep(1);
    }
    return 0;
}
void *thread_function(void *args)
{
    int i;
    for(i=1;i<=3;i++)
    printf("%d\n", i);
}