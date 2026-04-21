#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low+1 , j = high;
    while(1){
        while(i<=high && a[i]<=pivot)
            i++;
        while(a[j] > pivot)
            j--;
        if (i<j)
            swap(&a[i], &a[j]);
        else
            break;
    }
    swap(&a[low], &a[j]);
    return j;
}

void quicksort(int a[], int low, int high){
    if(low<high){
        int p = partition(a, low, high);
        quicksort(a, low, p-1);
        quicksort(a, p+1, high);
    }
}

int main(){
    int n, a[100], i;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        a[i] = rand()%(n*2);
        printf("%d\t", a[i]);
    }
    printf("\n");

    clock_t start, end;

    start = clock();
    quicksort(a, 0, n-1);
    end = clock();

    printf("The sorted elements are:\n");
    for(i=0;i<n;i++)
        printf("%d\t", a[i]);
    printf("\n");

    double t = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Time taken to execute: %lf", t);
    return 0;
}