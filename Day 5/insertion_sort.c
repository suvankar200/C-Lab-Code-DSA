#include <stdio.h>
#include <math.h>
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {

        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[] = {2, 6, 85, 25, 21, 36, 2, 54, 8, 9, 45, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    printf("After sorting");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    return 0;
}