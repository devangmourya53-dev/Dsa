/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct{int v,w;}Node;
Node heap[10000];
int size=0;
void swap(int i,int j){Node t=heap[i];heap[i]=heap[j];heap[j]=t;}
void push(int v,int w){
heap[size].v=v;
heap[size].w=w;
int i=size++;
while(i&&heap[(i-1)/2].w>heap[i].w){
swap(i,(i-1)/2);
i=(i-1)/2;
}
}
Node pop(){
Node r=heap[0];
heap[0]=heap[--size];
int i=0;
while(2*i+1<size){
int s=2*i+1;
if(s+1<size&&heap[s+1].w<heap[s].w)s++;
if(heap[i].w<=heap[s].w)break;
swap(i,s);
i=s;
}
return r;
}
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
}
int s;
scanf("%d",&s);
int*dist=(int*)malloc((n+1)*sizeof(int));
for(int i=1;i<=n;i++)dist[i]=INT_MAX;
dist[s]=0;
push(s,0);
while(size){
Node cur=pop();
int u=cur.v;
if(cur.w>dist[u])continue;
for(int v=1;v<=n;v++){
if(adj[u][v]!=INT_MAX&&dist[u]+adj[u][v]<dist[v]){
dist[v]=dist[u]+adj[u][v];
push(v,dist[v]);
}
}
}
for(int i=1;i<=n;i++){
if(dist[i]==INT_MAX)printf("INF");
else printf("%d",dist[i]);
if(i<n)printf(" ");
}
return 0;
}