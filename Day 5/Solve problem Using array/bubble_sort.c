#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int arr[], int n)
{
    int i, j;
    bool reverse;
    for (i = 0; i < n - 1; i++)
    {
        reverse = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                reverse = true;
            }
        }
    if (reverse==false)
    {
        break;
    }
    
    }

}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]); // Add a space between numbers
    }
    printf("\n");
}
int main()

{
    int arr[] = {2, 3, 11, 23, 3, 23, 34, 45, 65, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("after sorting\t");
    bubblesort(arr, n);
    print(arr, n);
    return 0;
}