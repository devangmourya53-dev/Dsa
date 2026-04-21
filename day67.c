/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include<stdio.h>
#include<stdlib.h>
int v;
int**adj;
int*vis;
int*stack;
int top=-1;
void dfs(int i){
vis[i]=1;
for(int j=0;j<v;j++){
if(adj[i][j]&&!vis[j])dfs(j);
}
stack[++top]=i;
}
int main(){
int e;
scanf("%d%d",&v,&e);
adj=(int**)malloc(v*sizeof(int*));
for(int i=0;i<v;i++){
adj[i]=(int*)calloc(v,sizeof(int));
}
for(int i=0;i<e;i++){
int a,b;
scanf("%d%d",&a,&b);
adj[a][b]=1;
}
vis=(int*)calloc(v,sizeof(int));
stack=(int*)malloc(v*sizeof(int));
for(int i=0;i<v;i++){
if(!vis[i])dfs(i);
}
for(int i=top;i>=0;i--){
printf("%d",stack[i]);
if(i)printf(" ");
}
return 0;
}