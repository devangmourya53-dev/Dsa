/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main(){
int n,m;
scanf("%d%d",&n,&m);
int**adj=(int**)malloc((n+1)*sizeof(int*));
for(int i=1;i<=n;i++){
adj[i]=(int*)malloc((n+1)*sizeof(int));
for(int j=1;j<=n;j++)adj[i][j]=INT_MAX;
}
for(int i=0;i<m;i++){
int u,v,w;
scanf("%d%d%d",&u,&v,&w);
adj[u][v]=w;
adj[v][u]=w;
}
int*key=(int*)malloc((n+1)*sizeof(int));
int*vis=(int*)calloc(n+1,sizeof(int));
for(int i=1;i<=n;i++)key[i]=INT_MAX;
key[1]=0;
int res=0;
for(int c=1;c<=n;c++){
int u=-1,min=INT_MAX;
for(int i=1;i<=n;i++){
if(!vis[i]&&key[i]<min){
min=key[i];
u=i;
}
}
vis[u]=1;
res+=key[u];
for(int v=1;v<=n;v++){
if(adj[u][v]!=INT_MAX&&!vis[v]&&adj[u][v]<key[v]){
key[v]=adj[u][v];
}
}
}
printf("%d",res);
return 0;
}