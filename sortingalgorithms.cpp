#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void swap(long long int *a, long long int *b)
{
    long long int temp = *a;
    *a = *b;
    *b = temp;
}
int getMax(long long int arr[], long long int n)
{
    long long int max = arr[0];
    for (long long int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(long long int a[], long long int n)
{
    long long int output[n + 1];
    long long int max = getMax(a, n);
    long long int count[max + 1];
    for (long long int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }
    for (long long int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    for (long long int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    for (long long int i = n - 1; i >= 0; i--)
    {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for (long long int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

void bucketSort(long long int arr[], long long int n)
{
    long long int max = getMax(arr, n);
    long long int bucket[max], i;
    for (long long int i = 0; i <= max; i++)
    {
        bucket[i] = 0;
    }
    for (long long int i = 0; i < n; i++)
    {
        bucket[arr[i]]++;
    }
    for (long long int i = 0, j = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            arr[j++] = i;
            bucket[i]--;
        }
    }
}
void countingSort(long long int arr[], long long int n, long long int place)
{
    long long int output[n + 1];
    long long int count[10] = {0};
    for (long long int i = 0; i < n; i++)
    {
        count[(arr[i] / place) % 10]++;
    }
    for (long long int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (long long int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }
    for (long long int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(long long int arr[], long long int n)
{
    long long int max = getMax(arr, n);
    for (long long int place = 1; max / place > 0; place *= 10)
    {
        countingSort(arr, n, place);
    }
}
void printArr(long long int arr[], long long int n)
{
    for (long long int i = 0; i < n; ++i)
    {
        printf("%d  ", arr[i]);
    }
}

int main()
{
    // long long int a[] = {54, 12, 84, 57, 69, 41, 9, 5};
    // long long int n = sizeof(a) / sizeof(a[0]);
    // printArr(a, n);
    // printf("\n");
    // countSort(a, n);
    // printArr(a, n);
    /*
    For an input in file we can also use--->

    ofstream fout("random.dat", ios::binary);
    srand(time(NULL));
    int r;
    for (size_t i = 0; i < length; i++)
    {
        r = rand();
        fout.write((char*)&r, sizeof(r));
    }
    fout.close();

    */

    long long int n = 10000;
    long long int it = 0;
    double tim1[10], tim2[10], tim3[10];
    printf("A_size, Bubble, Insertion, Selection\n");
    while (it++ < 10)
    {
        long long int a[n], b[n], c[n];
        for (long long int i = 0; i < n; i++)
        {
            long long int no = rand() % n + 1;
            a[i] = no;
            b[i] = no;
            c[i] = no;
        }
        clock_t start, end;
        start = clock();
        radixSort(a, n);
        end = clock();
        tim1[it] = ((double)(end - start));
        start = clock();
        bucketSort(b, n);
        end = clock();
        tim2[it] = ((double)(end - start));
        start = clock();
        countSort(c, n);
        end = clock();
        tim3[it] = ((double)(end - start));
        printf("%li, %li, %li, %li\n", n, (long int)tim1[it], (long int)tim2[it], (long int)tim3[it]);
        n += 10000;
    }
    return 0;
}