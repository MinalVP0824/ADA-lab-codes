#include<stdio.h>
#define MAX 20
#define INF 999

int Parent[MAX+1] = {0};

int find(int x){
    while(Parent[x])
        x = Parent[x];
    return x;
}

int main(){
    int n, cost[MAX+1][MAX+1];
    int i, j, u, v, min;
    int totalCost = 0, edges = 0;

    printf("Enter ther number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d", &cost[i][j]);
            if(i!= j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Edges in MST:\n");
    while(edges <n-1){
        min = INF;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min){
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int a = find(u);
        int b = find(v);

        if(a!=b){
            printf("%d -> %d, Cost: %d\n", u, v, min);
            totalCost += min;
            Parent[b] = a;
            edges++;
        }
        cost[u][v] = cost[v][u] = INF;
    }
    printf("Total MST Cost: %d", totalCost);
    return 0;
}