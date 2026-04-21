#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[], int low, int mid, int high){
    int i=low, j=mid+1, k=low;
    int b[high+1];
    while(i<=mid && j<=high){
        if(arr[i]<arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }
    while(i<=mid)
        b[k++] = arr[i++];
    while(j<=high)
        b[k++] = arr[j++];

    for(i=low;i<=high;i++)
        arr[i] = b[i];
}

void mergesort(int arr[], int low, int high){
    if(low<high){
        int mid = low+(high-low)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main(){
    int i, n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n];

    for(i=0;i<n;i++){
        arr[i] = rand()%(n*2);
        printf("%d\t", arr[i]);
    }
    printf("\n");

    clock_t start, end;

    start = clock();
    mergesort(arr, 0, n-1);
    end = clock();

    printf("Sorted elements are:\n");
    for(i=0;i<n;i++)
        printf("%d\t", arr[i]);
    printf("\n");

    double t = (end - start) / (double) CLOCKS_PER_SEC;
    printf("Time taken to execute: %lf", t);
    return 0;

}