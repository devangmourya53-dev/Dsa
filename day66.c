/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include<stdio.h>
#include<stdlib.h>
int v;
int**adj;
int*vis;
int*rec;
int dfs(int i){
vis[i]=1;
rec[i]=1;
for(int j=0;j<v;j++){
if(adj[i][j]){
if(!vis[j]&&dfs(j))return 1;
else if(rec[j])return 1;
}
}
rec[i]=0;
return 0;
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
rec=(int*)calloc(v,sizeof(int));
for(int i=0;i<v;i++){
if(!vis[i]){
if(dfs(i)){
printf("YES");
return 0;
}
}
}
printf("NO");
return 0;
}