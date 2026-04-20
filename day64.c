/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/
#include<stdio.h>
#define MAX 100

int adj[MAX][MAX],visited[MAX],queue[MAX];

int main(){
int n,i,j,m,u,v,s,front=0,rear=0;

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

scanf("%d",&s);

for(i=0;i<n;i++)visited[i]=0;

queue[rear++]=s;
visited[s]=1;

while(front<rear){
int x=queue[front++];
printf("%d ",x);
for(i=0;i<n;i++){
if(adj[x][i]==1 && visited[i]==0){
queue[rear++]=i;
visited[i]=1;
}
}
}

return 0;
}