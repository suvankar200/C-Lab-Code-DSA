#include <stdio.h>

int main() {
   int arr[10];
   int n;
   printf("Enter the number which you want to search");
   scanf("%d", &n);
   int i;
   for(i=0; i<5; i++)
   {
   
   printf("Enter the array");
   scanf("%d", &arr[i]);
       
   }
   i=0;
while(i<5)
{
    
      if(arr[i]==n)
      {
          printf("Element %d is find in %d index\n",n,i);
          return 1;
      }
      i++;
}
printf("Element is not found");
          

   return 0;
}