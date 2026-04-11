/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/
#include <stdio.h>
#include <stdlib.h>

struct Node{int data;struct Node*next;};

struct Node*newNode(int v){
    struct Node*node=(struct Node*)malloc(sizeof(struct Node));
    node->data=v;
    node->next=NULL;
    return node;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    struct Node*adj[n];
    for(int i=0;i<n;i++)adj[i]=NULL;
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        struct Node*node=newNode(v);
        node->next=adj[u];
        adj[u]=node;
        node=newNode(u);
        node->next=adj[v];
        adj[v]=node;
    }
    for(int i=0;i<n;i++){
        printf("%d:",i);
        struct Node*temp=adj[i];
        while(temp){
            printf(" %d",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    return 0;
}