/*Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}*/
#include<stdio.h>
#include<stdlib.h>
int n;
int**adj;
int*vis;
void dfs(int i){
vis[i]=1;
for(int j=1;j<=n;j++){
if(adj[i][j]&&!vis[j])dfs(j);
}
}
int main(){
int m;
scanf("%d%d",&n,&m);
adj=(int**)malloc((n+1)*sizeof(int*));
for(int i=1;i<=n;i++)adj[i]=(int*)calloc(n+1,sizeof(int));
for(int i=0;i<m;i++){
int u,v;
scanf("%d%d",&u,&v);
adj[u][v]=1;
adj[v][u]=1;
}
vis=(int*)calloc(n+1,sizeof(int));
int count=0;
for(int i=1;i<=n;i++){
if(!vis[i]){
dfs(i);
count++;
}
}
printf("%d",count);
return 0;
}
