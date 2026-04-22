/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct{int u,v,w;}Edge;
int main(){
int n,m;
scanf("%d%d",&n,&m);
Edge*e=(Edge*)malloc(m*sizeof(Edge));
for(int i=0;i<m;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
int s;
scanf("%d",&s);
int*dist=(int*)malloc(n*sizeof(int));
for(int i=0;i<n;i++)dist[i]=INT_MAX;
dist[s]=0;
for(int i=1;i<n;i++){
for(int j=0;j<m;j++){
if(dist[e[j].u]!=INT_MAX&&dist[e[j].u]+e[j].w<dist[e[j].v])
dist[e[j].v]=dist[e[j].u]+e[j].w;
}
}
for(int j=0;j<m;j++){
if(dist[e[j].u]!=INT_MAX&&dist[e[j].u]+e[j].w<dist[e[j].v]){
printf("NEGATIVE CYCLE");
return 0;
}
}
for(int i=0;i<n;i++){
if(dist[i]==INT_MAX)printf("INF");
else printf("%d",dist[i]);
if(i<n-1)printf(" ");
}
return 0;
}