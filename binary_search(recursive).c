#include <stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int low, int high, int x)
{
	if (low <= high)
	{
		int mid = (low + high)/2;

		if (arr[mid] == x) 
		{
			printf("Element is present at index %d", mid+1);
			return mid;
		}

		if (arr[mid] > x) 
			return binarySearch(arr, low, mid-1, x);

		return binarySearch(arr, mid+1, high, x);
	}	

	printf("Element is not present in array");
	return -1;
}

int main()
{
	int *a,n,i,x;
	printf("\nEnter the total number of elements in the array : ");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));s
	printf("\nEnter elements of the array in ascending order  : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter element to be searched : ");
	scanf("%d",&x);
	binarySearch(a, 0, n-1, x);
	return 0;
}
