#include <stdio.h>
#include <string.h>
void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int main()  
{  
    int n,i=0,j=0,a;
	printf("Enter the size of the array:");
	scanf("%d",&n);  
    int arr[n];   
    for(i=0;i<n;i++){
    	printf("Enter %d th element of the array:",i+1);
    	scanf("%d",&arr[i]);
	}
	for (i = 0; i < n; ++i) 
        {
 
            for (j = i + 1; j < n; ++j)
            {
 
                if (arr[i] > arr[j]) 
                {
 
                    a =  arr[i];
                    arr[i] = arr[j];
                    arr[j] = a;
 
                }
 
            }
 
        }
        
    int length = sizeof(arr)/sizeof(arr[0]);  
    int fr[length];  
    int visited = -1;  
      
    for(int i = 0; i < length; i++){  
        int count = 1;  
        for(int j = i+1; j < length; j++){  
            if(arr[i] == arr[j]){  
                count++;  
                fr[j] = visited;  
            }  
        }  
        if(fr[i] != visited)  
            fr[i] = count;  
    }    
    printf("Frequencies of the respective elements are:\n");
    for(int i = 0; i < length; i++){  
        if(fr[i] != visited){  
            printf("    %d", arr[i]);  
            printf("    |  ");  
            printf("  %d\n", fr[i]);  
        }  
    }  
    int r=sizeof(fr)/sizeof(fr[0]);
	mergeSort(fr,0,r-1); 
	printf("The sorted intermediate array using merge sort in ascending order is:");
	for(i=0;i<r;i++){
		if(fr[i]==-1){
			continue;
		}
		else{
			printf("%d ",fr[i]);
		}
	}
	printf("\nThe sorted intermediate array using merge sort in descending order is:");
	for(i=r-1;i>=0;i--){
		if(fr[i]==-1){
			continue;
		}
		else{
			printf("%d ",fr[i]);
		}
	}
    return 0;  
}  
