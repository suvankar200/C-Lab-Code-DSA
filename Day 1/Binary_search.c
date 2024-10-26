#include <stdio.h>

int binarysearch(int arr[], int n, int target);

int main()
{
    int n = 5;
    int arr[5];
    int i, t;
    
    // Input elements of the array
    for(i = 0; i < 5; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the target: ");
    scanf("%d", &t);
    
    int a = binarysearch(arr, n, t);
    
    if(a != -1)
    {
        printf("Element found at index %d\n", a);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}

int binarysearch(int arr[], int n, int target) 
{
    int low = 0;
    int high = n - 1;
    
    while(low <= high)
    {
        int mid = (low + high) / 2;
        
        if(arr[mid] == target)
        {
            return mid;  // Return the index of the found element
        }
        else if(arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return -1;  // Element not found
}
