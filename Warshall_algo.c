#include<stdio.h>

int main(){
    int i, j, k, n;

    printf("Enter the  number of vertices: ");
    scanf("%d", &n);

    int p[10][10];

    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &p[i][j]);
        }
    }

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                    p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
            }
        }
    }

    printf("\nTransitive Closure matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    return 0;
}