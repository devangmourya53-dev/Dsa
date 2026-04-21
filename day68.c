/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include<stdio.h>
#include<stdlib.h>
int main(){
int v,e;
scanf("%d%d",&v,&e);
int**adj=(int**)malloc(v*sizeof(int*));
for(int i=0;i<v;i++)adj[i]=(int*)calloc(v,sizeof(int));
int*indeg=(int*)calloc(v,sizeof(int));
for(int i=0;i<e;i++){
int a,b;
scanf("%d%d",&a,&b);
adj[a][b]=1;
indeg[b]++;
}
int*q=(int*)malloc(v*sizeof(int));
int f=0,r=0;
for(int i=0;i<v;i++){
if(indeg[i]==0)q[r++]=i;
}
int cnt=0;
while(f<r){
int x=q[f++];
printf("%d",x);
cnt++;
if(cnt<v)printf(" ");
for(int j=0;j<v;j++){
if(adj[x][j]){
indeg[j]--;
if(indeg[j]==0)q[r++]=j;
}
}
}
return 0;
}