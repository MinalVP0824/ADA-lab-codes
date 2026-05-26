#include<stdio.h>
#define MAX 20

int w[MAX];
short x[MAX];
int d, solcount = 0;

void subset(int currSum, int k, int remSum){
    x[k] = 1;

    if(currSum + w[k] == d){

        printf("%d. ", ++solcount);

        for(int i=0;i<=k;i++){
            if(x[i])
                printf("%d ", w[i]);
        }
        printf("\n");
    }

    else if(currSum + w[k] + w[k+1] <= d)
        subset(currSum + w[k], k+1, remSum - w[k]);
    
    if((currSum + remSum - w[k] >= d) && (currSum + w[k+1] <= d)){
        x[k] = 0;
        subset(currSum, k+1, remSum - w[k]);
    }
}

int main(){
    int N, sum;
    
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    sum = 0;

    printf("Enter the set of elements in increasing order: ");
    for(int i=0;i<N;i++){
        scanf("%d", &w[i]);
        sum +=  w[i];
    }
    
    printf("Enter the target sum: ");
    scanf("%d", &d);

    if(sum >= d){
        printf("\nPossible subsets are:\n");
        subset(0, 0, sum);
    }
    else
        printf("\nNo possible subsets");
    return 0;
}
