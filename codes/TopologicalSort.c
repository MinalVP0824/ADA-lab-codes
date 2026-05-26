#include<stdio.h>
#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX], top = -1;
int n;

void dfs(int v){
    visited[v] = 1;

    for(int i=0;i<n;i++){
        if(adj[v][i] == 1 && !visited[i])
            dfs(i);   
    }

    stack[++top] = v;
}

int main(){
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &adj[i][j]);
        }
    }

    for(int i=0;i<n;i++)
        visited[i] = 0;

    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(i);
    }
    
    printf("Topological Sort:\n");
    while(top!=-1)
        printf("%d\t", stack[top--]);
    return 0;
}