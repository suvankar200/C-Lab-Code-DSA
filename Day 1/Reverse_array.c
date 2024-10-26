#include <stdio.h>
int main()
{
    int arr[5];
    int i;
    for(i=0;i<5;i++)
    {
        
    printf("Enter the element\n");
    scanf("%d", &arr[i]);
    }
    printf("Your original array\t");
    for(i=0; i<5; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("Your array in reverse order\t");
    for(i=4;i>=0;i--)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
    
}