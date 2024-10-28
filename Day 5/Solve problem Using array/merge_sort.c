#include <stdio.h>
#include <stdlib.h>
void mergesort(int arr[], int left, int right, int mid)
{
    int i, j, k;
    int l1 = mid - left + 1;
    int l2 = right - mid;

    int L[l1], R[l2];
    for(i=0;i<l1;i++)
    {
        L[i]=arr[left+i];

    }
    for(j=0;j<l2;j++)
    {
        R[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=left;
    while (i < l1 && j < l2)
    {
        if(L[i]>=R[j])
        {
            arr[k]=R[j];
            j++;
        }
        else{
            arr[k]=L[i];
            i++;
        }
        k++;
    }
    while (i < l1) {
    arr[k] = L[i];
    i++;
    k++;
}
while (j < l2) {
    arr[k] = R[j];
    j++;
    k++;
}

}

void merge(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge(arr, left, mid);
        merge(arr, mid + 1, right);
      mergesort(arr,left,right,mid);
    }
}
void printelement(int arr[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[]={2,65,8,25,75,26,35,75};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Before sorting\t");
    printelement(arr,n);
    merge(arr,0,n-1);
    printf("After sort\t");
    printelement(arr,n);
    return 0;

}