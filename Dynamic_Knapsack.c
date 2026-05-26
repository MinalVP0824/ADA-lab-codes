#include<stdio.h>
#define max(x, y) (x > y? x : y)

void dKnapsack(int profit[], int weight[], int N, int M){
    int dp[N+1][M+1];
    int i, w;

    for(i=0;i<=N;i++)
        for(w=0;w<=M;w++){
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if( w >= weight[i-1])
                dp[i][w] = max(dp[i-1][w], profit[i-1] + dp[i-1][w-weight[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    int result = dp[N][M];

    printf("Maximum Profit: %d\n", result);
    printf("Solution vector:\n");
    for(i=N;i>0 && result>0;i--){
        if (result != dp[i-1][w]){
            printf("1 ");
            result -= profit[i-1];
            w -= weight[i-1];
        }
        else
            printf("0 ");
    }
}

int main(){
    int N;

    printf("Enter the number of objects: ");
    scanf("%d", &N);

    int profit[N];
    printf("Enter the profits: ");
    for(int i=0;i<N;i++)
        scanf("%d", &profit[i]);
    
    int weight[N];
    printf("Enter the weights: ");
    for(int i=0;i<N;i++)
        scanf("%d", &weight[i]);
    
    int M;
    printf("Enter the Knapsack capacity: ");
    scanf("%d", &M);

    dKnapsack(profit, weight, N, M);

    return 0;
}