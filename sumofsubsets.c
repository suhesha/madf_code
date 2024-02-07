
#include<stdio.h>
int i;
int n;		//total number of elements
int m;	    //Given capacity/Sum
	
	


void SumOfSubsets(int s,int k,int r,int x[n],int w[n])
{
	
    x[k] = 1;
    if(s + w[k] == m)
    {
		 
		  for(i=0;i<n;i++) {
				printf(" %d",x[i]);
		  }
		  printf("\n");
    }
    else if(s + w[k] + w[k+1] <= m)
    {
        SumOfSubsets(s+w[k],k+1,r-w[k],x,w);
    }
    if((s+r-w[k] >= m) && (s+w[k+1] <= m))
    {
        x[k] = 0;
        SumOfSubsets(s,k+1,r-w[k],x,w);
    }
}
int main()
{
    
    int r=0;
    
    printf("\nEnter the value of N : ");
    scanf("%d",&n);
    int x[n];
    for(i=0;i<n;i++)
    {
        x[i]=0;
    }
    
    int w[n];
    printf("\nEnter the value of M : ");
    scanf("%d",&m);
    printf("\nEnter the Weights : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }
    for(i=0;i<n;i++)
    {
        r = r + w[i];
    }
    
    printf("\nSolutions are : \n");
    SumOfSubsets(0,0,r,x,w);
    return 0;
}
