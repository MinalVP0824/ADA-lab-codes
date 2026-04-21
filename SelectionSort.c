#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int sel_sort(int a[], int n){
    int i, j, min, temp;
    clock_t start = clock();
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    clock_t end = clock();
    for(i=0;i<n;i++)
        printf("%d\t", a[i]);
    printf("\n");
    
    double t = (start-end)/(double) CLOCKS_PER_SEC;
    printf("Time Complexity: %lf", t);
}

int main(){
    int i, a[100], n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        a[i] = rand()%10;
        printf("%d\t", a[i]);
    }
    printf("\n");
    sel_sort(a,n);
}