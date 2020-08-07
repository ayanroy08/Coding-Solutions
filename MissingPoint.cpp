#include<stdio.h>
#include <stdlib.h> 
  
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(long int arr[],long int l,long int m,long int r) 
{ 
   long int i, j, k; 
   long int n1 = m - l + 1; 
   long int n2 = r - m; 
  
    /* create temp arrays */
   long int L[n1], R[n2]; 
  
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
void mergeSort(long int arr[],long int l,long int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
int main()
{
	long int t;
	scanf("%ld",&t);
	while(t--)
	{
		long int i,n,N,k=0;
		scanf("%ld",&N);
		n=(4*N)-1;
		long int X[n],Y[n];
		
		for(i=0;i<n;i++)
		{
			scanf("%ld",&X[i]);
			scanf("%ld",&Y[i]);
		}
		mergeSort(X,0,n-1);
		mergeSort(Y,0,n-1);
		long int Xc=0,Yc=0,cX=0,cY=0;
		
		for(i=0;i<n-1;i++)
		{
			if(X[i]==X[i+1])
			{
				cX++;
			}
			else
			{
				cX++;
				if(cX%2!=0)
				Xc=X[i];
				cX=0;
			}
			if(Y[i]==Y[i+1])
			{
				cY++;
			}
			else
			{
				cY++;
				if(cY%2!=0)
				Yc=Y[i];
				cY=0;
			}		
		}
		cX++;
		if(cX%2!=0)
		Xc=X[i];
		cX=0;
		cY++;
		if(cY%2!=0)
		Yc=Y[i];
		cY=0;
		printf("%ld %ld\n",Xc,Yc);
	}
}
