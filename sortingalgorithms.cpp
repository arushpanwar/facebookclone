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
void merge(long long int array[], long long int const left, long long int const mid, long long int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
         indexOfSubArrayTwo = 0;
    long long int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
void mergeSort(long long int array[], long long int const begin, long long int const end)
{
    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
int partition(long long int arr[], long long int low, long long int high)
{
    long long int pivot = arr[high];
    long long int i = (low - 1);
    for (long long int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(long long int arr[], long long int low, long long int high)
{
    if (low < high)
    {
        long long int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    long long int a[] = {2, 5, 84, 57, 6, 41, 9, 5};
    long long int n = sizeof(a) / sizeof(a[0]);
    printArr(a, n);
    printf("\n");
    quickSort(a, 0, n - 1);
    printArr(a, n);
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

    // long long int n = 10000;
    // long long int it = 0;
    // double tim1[10], tim2[10];
    // printf("A_size, Merge, Quick\n");
    // while (it++ < 10)
    // {
    //     long long int a[n], b[n];
    //     for (long long int i = 0; i < n; i++)
    //     {
    //         long long int no = rand() % n + 1;
    //         a[i] = no;
    //         b[i] = no;
    //     }
    //     clock_t start, end;
    //     start = clock();
    //     mergeSort(a, 0, n - 1);
    //     end = clock();
    //     tim1[it] = ((double)(end - start));
    //     start = clock();
    //     quickSort(b, 0, n - 1);
    //     end = clock();
    //     tim2[it] = ((double)(end - start));
    //     printf("%li, %li, %li\n", n, (long int)tim1[it], (long int)tim2[it]);
    //     n += 10000;
    // }
    return 0;
}
