/*Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED*/
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
dfs(1);
for(int i=1;i<=n;i++){
if(!vis[i]){
printf("NOT CONNECTED");
return 0;
}
}
printf("CONNECTED");
return 0;
}