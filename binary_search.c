#include<stdio.h>
#include<stdlib.h>

void binary_search(int *, int,int);

int main()
{
	
	int *a,n,i,x;
	printf("\nEnter the total number of elements in the array : ");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("\nEnter elements of the array in ascending order  : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter element to be searched : ");
	scanf("%d",&x);
	
	
	
	binary_search(a,n,x);
	
	return 0;
	
}

void binary_search(int *a,int n, int x)
{
	int low,high,mid;
	low=0;
	high=n-1;
	mid=(low+high)/2;
	
	while(low<=high)
	{
		if( x > a[mid] )
		{
			low=mid+1;
			
		}
		if( x < a[mid] )
		{
			high=mid-1;
		}
		if( x== a[mid] )
		{
			printf("\nElement found at position %d ",mid+1);
			break;
		}
	mid=(low+high)/2;	
	}
	
	if(low>high)
	{
		printf("\nElement not found !!");
	}
	
}
