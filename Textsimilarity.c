#include<stdio.h>
#include<string.h>
int max(int m ,int n)
{
		if (m>n)
			return m;
		else 
			return n;
	
	
}
int longestCommonSubsequece(char str1[],char str2[], int len1,int len2)
{
	int i,j;
    //create a matrix LCS of order (len1+1)*(len2+1) to tabulate values
	 int LCS[len1+1][len2+1];
   //initializing
    for(i=0;i<=len1;i++)
        LCS[i][0]=0;    //empty str2
 
    for(j=0;j<=len2;j++)
        LCS[0][j]=0;   //empty str1
 
    //now, start filling the matrix row wise
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            //if current character of both strings match
            if(str1[i-1]==str2[j-1])
            {
                LCS[i][j]=1+LCS[i-1][j-1];
            }
 
            //mismatch
            else
            {
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
    }
    
     printf("\nMatrix  : \n");
     for(i=0;i<=len1;i++)
    {
        for(j=0;j<=len2;j++)
        {
			printf("%d ",LCS[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
	int index = LCS[len1][len2];  
  char string[index + 1];  
  string[index] = '\0';  
  
   i = len1, j = len2;  
  while (i > 0 && j > 0) {  
    if (str1[i - 1] == str2[j - 1]) {  
      string[index - 1] = str1[i - 1];  
      i--;  
      j--;  
      index--;  
    }  
  
    else if (LCS[i - 1][j] > LCS[i][j - 1])  
      i--;  
    else  
      j--;  
  }  
   
 
  printf("\nString: %s \n", string);  
  
  
  
  
  
     return LCS[len1][len2];
 
}

int main()
{	
		char a[20],b[20];
		int len1,len2;
		printf("\nEnter string 1 : ");
		scanf("%s",a);
		printf("\nEnter string 2 : ");
		scanf("%s",b);
		
		len1 = strlen(a);
		len2 = strlen(b);
		
		printf("Lenght = %d ",longestCommonSubsequece(a,b,len1,len2));
	
	
	
		return 0;
}
