#include<stdio.h>
#include <stdlib.h> 
  
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(long int arr[], long int l, long int m, long int r) 
{ 
    long int i, j, k; 
    long int n1 = m - l + 1; 
    long int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(long int arr[],long  int l, long int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
       long int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
long int min(long int A,long int B)
{
	if(A<B)
	return(A);
	else
	return(B);
}
  
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long int i,j,n,k=0;
		scanf("%ld",&n);
		long int A[n],B[n],C[2*n];
		for(i=0;i<n;i++)
		{
			scanf("%ld",&A[i]);
			C[i]=A[i];
		}
		for(j=0;j<n;j++)
		{
			scanf("%ld",&B[j]);
			C[j+n]=B[j];
		}
		long int Half[n];
		long int c=0,t=0,cost=0;
		mergeSort(C,0,(2*n)-1);
		for(i=0;i<(2*n)-1;i++)
		{
			if(C[i]!=C[i+1])
			{
				t++;
			}
			if(i%2==0)
			{
				Half[i/2]=C[i];
			}
		}
		t++;
		long int Awrong[n],Bwrong[n],aright=0,bright=0;
		long int U[t],f[t],r=0,co=1;
		for(i=0;i<t;i++)
		{
			U[i]=0;
			f[i]=0;
		}
		for(i=0;i<(2*n)-1;i++)
		{
			if(C[i]!=C[i+1])
			{
				U[r]=C[i];
				f[r]=co;
				r++;
				co=1;
			}
			else
				co++;	
		}
		U[r]=C[i];
		if(co>=1)
		{
			f[r]=co;
		}
		else
		{
			f[r]=1;
		}
		for(i=0;i<t;i++)
		{
			if(f[i]%2!=0)
				k=1;
			f[i]=f[i]/2;
		}
		
		if(k==0)
		{
			int check=0;
			mergeSort(A,0,n-1);
			mergeSort(B,0,n-1);
			for(i=0;i<n;i++)
			{
				if(A[i]!=B[i])
				check=1;
			}
			if(check==0)
				cost=0;
			else
			{
				
				i=0;j=0;
				co=0;r=0;
				long int ua[n],ub[n];
				for(i=0;i<n;i++)
				{
					ua[i]=0;
					ub[i]=0;
				}
				i=0;j=0;
				while((i<n)&&(j<n))
				{
					if(A[i]<Half[j])
					{
						i++;
					}
					else if(Half[j]<A[i])
					{
						j++;
					}
					else
					{
						
						ua[i]=A[i];
						i++;
						j++;
					}
					
				}
				
				i=0;j=0;r=0;
				while((i<n)&&(j<n))
				{
					if(B[i]<Half[j])
					{
						i++;
					}
					else if(Half[j]<B[i])
					{
						j++;
					}
					else
					{
						ub[i]=B[i];
						i++;
						j++;
					}
				}
				j=0;k=0;
				for(i=0;i<n;i++)
				{
					if((ua[i]!=A[i]))
					{
						Awrong[j]=A[i];
						j++;
					}	
					if((ub[i]!=B[i]))
					{
						Bwrong[k]=B[i];
						k++;
					}	
				}
				long int temp=0;
				for(i=0;i<j;i++)
				{
					temp=min(Awrong[i],Bwrong[j-i-1]);
					if((2*Half[0])<temp)
					cost=cost+(2*Half[0]);
					else
					cost=cost+temp;
				}
			}
			printf("%ld\n",cost);
		}
		else
			printf("-1\n");
		
	}
	return 0;
}

