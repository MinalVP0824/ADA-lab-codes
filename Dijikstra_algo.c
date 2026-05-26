#include<stdio.h>
#define INF 999 

int n, s[20], d[20], p[20], adj[20][20];

void dijikstra(int src){

    for(int i=0;i<n;i++){
        s[i] = 0;
        d[i] = adj[src][i];
        p[i] = src;
    }
    s[src] = 1;
    for(int i=0;i<n-1;i++){
        int min = INF, u;
        for(int j=0;j<n;j++){
            if(!s[j] && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        s[u] = 1;
        for(int v=0;v<n;v++){
            if(!s[v] && d[u]+adj[u][v] < d[v]){
                d[v] = d[u] + adj[u][v];
                p[v] = u;
            }
        }
    }
}

int main(){
    int src;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &adj[i][j]);

            if(i != j && adj[i][j] == 0)
                adj[i][j] = INF;
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijikstra(src);

    printf("\nThe shortest path from the source %d is:\n", src);
    for(int i=0;i<n;i++){
        printf("%d -> %d: %d\n", src, i, d[i]);
    }

    return 0;
}