#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
pthread_t th[3];
int x;
void *thread_function(void *args);
int main()
{
    int i;
    for(i=0;i<3;i++)
    {
        pthread_create(&th[i], NULL, thread_function, NULL);
        sleep(1);
        printf("with value of x = %d\n", x);
    }
    return 0;
}
void *thread_function(void *args)
{
    static int c=0;
    c++;
    printf("Thread number is %d ", c);
    if(pthread_equal(pthread_self(), th[0]))
    x=10;
    else if(pthread_equal(pthread_self(), th[1]))
    x=100;
    else
    x=1000;
}