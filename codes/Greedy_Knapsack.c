#include<stdio.h>
#define max 50
typedef struct{
    int profit, weight;
    double ratio;
    int index;
} item;

void Gknapsack(item items[], int N, int M){
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(items[i].ratio < items[j].ratio){
                item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
    int currentWeight = 0;
    double maxProfit = 0;
    double X[max] = {0.0};

    for(int i=0;i<N;i++){
        if(currentWeight + items[i].weight <= M){
            X[items[i].index] = 1.0;
            maxProfit += items[i].profit;
            currentWeight += items[i].weight;
        }
        else{
            X[items[i].index] = (M-currentWeight)/(double)(items[i].weight);
            maxProfit += X[items[i].index] * items[i].profit;
            break;
        }
    }

    printf("Optimal Solution: %.1f\n", maxProfit);
    printf("Solutions Vector X[]: ");

    for(int i=0;i<N;i++)
        printf("%.1f ",X[i]);

    printf("\n");
}

int main(){
    int N;
    printf("Enter the number of objects: ");
    scanf("%d", &N);

    item items[N];

    printf("Enter the profits: ");
    for(int i=0;i<N;i++)
        scanf("%d",&items[i].profit);
    
    printf("Enter the weights: ");
    for(int i=0;i<N;i++){
        scanf("%d", &items[i].weight);

        items[i].ratio = (double) items[i].profit / items[i].weight;

        items[i].index = i;
    }
    
    int M;
    printf("Enter the maximum capacity: ");
    scanf("%d", &M);

    Gknapsack(items, N, M);

    return 0;
}