/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/
#include<stdio.h>
#define MAX 100

int adj[MAX][MAX],visited[MAX],flag=0,n;

void dfs(int v,int parent){
visited[v]=1;
for(int i=0;i<n;i++){
if(adj[v][i]==1){
if(!visited[i]) dfs(i,v);
else if(i!=parent) flag=1;
}
}
}

int main(){
int m,u,v,i,j;

scanf("%d",&n);
scanf("%d",&m);

for(i=0;i<n;i++)
for(j=0;j<n;j++)
adj[i][j]=0;

for(i=0;i<m;i++){
scanf("%d%d",&u,&v);
adj[u][v]=1;
adj[v][u]=1;
}

for(i=0;i<n;i++){
if(!visited[i]) dfs(i,-1);
}

if(flag) printf("YES");
else printf("NO");

return 0;
}