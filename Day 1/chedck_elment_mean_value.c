#include <stdio.h>
int main()
{
    int arr[5];
    int i;
    int n = 5;
    for (i = 0; i < n; i++)
    {
        printf("Enter your element of %d =",i+1);
        scanf("%d", &arr[i]);
    }
    if (arr[0] < arr[1])

    {
        printf("your mini is %d in index %d\n",arr[0],0 );
    }
     if (arr[n-1] < arr[n - 2])
    {
        printf("Your mini is %d in index %d\n",arr[n-1],n-1);
    }
    for (i = 1; i < n-1; i++)
    {

        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
        {
            printf("Your mini is %d in index %d\n",arr[i],i);
        }
    }
    return 0;
}