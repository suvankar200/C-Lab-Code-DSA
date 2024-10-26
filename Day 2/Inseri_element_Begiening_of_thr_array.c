#include <stdio.h>
int main()
{
	int n=5;
	int arr[n];
	int val;
	int narr[n+1];
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter your element");
		scanf("%d", &arr[i]);
	}
	for(i=1;i<=n;i++)
	{
		narr[i]=arr[i-1];
	}
	printf("Enter one element which one you want to add");
	scanf("%d", &val);
    narr[0]=val;
    printf("Your new array\t");
    for(i=0; i<=n;i++)
    {
    	printf("%d\t",narr[i]);
	}
	return 0;
}