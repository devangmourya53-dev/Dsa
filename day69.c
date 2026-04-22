/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/
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
int v,e;
scanf("%d%d",&v,&e);
int**adj=(int**)malloc(v*sizeof(int*));
for(int i=0;i<v;i++)adj[i]=(int*)malloc(v*sizeof(int));
for(int i=0;i<v;i++)for(int j=0;j<v;j++)adj[i][j]=INT_MAX;
for(int i=0;i<e;i++){
int a,b,w;
scanf("%d%d%d",&a,&b,&w);
adj[a][b]=w;
}
int s;
scanf("%d",&s);
int*dist=(int*)malloc(v*sizeof(int));
for(int i=0;i<v;i++)dist[i]=INT_MAX;
dist[s]=0;
push(s,0);
while(size){
Node n=pop();
int u=n.v;
if(n.w>dist[u])continue;
for(int j=0;j<v;j++){
if(adj[u][j]!=INT_MAX&&dist[u]+adj[u][j]<dist[j]){
dist[j]=dist[u]+adj[u][j];
push(j,dist[j]);
}
}
}
for(int i=0;i<v;i++){
if(dist[i]==INT_MAX)printf("INF");
else printf("%d",dist[i]);
if(i<v-1)printf(" ");
}
return 0;
}