#include<stdio.h>
#define MAX 20
#define INF 999
int main(){
    int n, cost[MAX+1][MAX+1];
    int visited[MAX+1] = {0};
    int i, j, u = 0, v = 0, min;
    int totalCost = 0, edges = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost Adjacency matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[1] = 1;

    printf("Edges in MST:\n");

    while(edges < n-1){
        min = INF;

        for(i=1;i<=n;i++){
            if(visited[i]){
                for(j=1;j<=n;j++){
                    if(!visited[j] && cost[i][j] < min){
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        printf("%d -> %d, cost: %d\n", u, v, min);
        totalCost += min;
        visited[v] = 1;
        edges++;
    }
    printf("Total cost of MST: %d", totalCost);
    return 0;
}