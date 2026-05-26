#include<stdio.h>

int x[10];

int place(int x[], int k){
    for(int i=1;i<k;i++){
        if(x[i] == x[k] || i-x[i] == k-x[k] || i+x[i] == k+x[k])
            return 0;
    }
    return 1;
}

void placeQueens(int k, int x[], int n){
    while (k > 0){
        x[k] = x[k] + 1;
        while((x[k] <= n) && (!place(x, k)))
            x[k] = x[k] + 1;
        
        if(x[k] <= n){
            if(k == n)
                return;
            else{
                k++;
                x[k] = 0;
            }
        } 
        else
            k--;
    }
}

int main(){
    int q = 1, i, j, n;
    x[q] = 0;

    printf("Enter the number if queens: ");
    scanf("%d", &n);

    placeQueens(q, x, n);

    for(i=1;i<=n;i++)
        printf("The Queen %d is placed at (%d, %d)\n", i, i, x[i]);
        
    return 0;
}