#include<stdio.h>
#define INF 999

int main(){
    int i, j, k, n;

    printf("Enter the  number of vertices: ");
    scanf("%d", &n);

    int p[10][10];

    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &p[i][j]);

            if(i!=j && p[i][j] == 0)
                p[i][j] = INF;
        }
    }

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(p[i][k] != INF && p[k][j] != INF && p[i][j] > p[i][k] + p[k][j])
                    p[i][j] = p[i][k] + p[k][j];
            }
        }
    }

    printf("\nShortest path matrix: ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(p[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}