#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int high, int low)
{
    int h = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {

        if (arr[j] < h)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quicksort(int arr[], int high, int low)
{
    if (low < high)
    {
        int pi = partition(arr, high, low);
        quicksort(arr, pi - 1, low);
        quicksort(arr, high, pi + 1);
    }
}
void print(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[10] = {2, 5, 2, 7, 5, 3, 54, 34, 53, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, n - 1, 0);
    printf("The sorted array is \n");
    print(arr, n);
    return 0;
}

