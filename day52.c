/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

struct Node* buildTree(int arr[],int n){
    if(n==0||arr[0]==-1) return NULL;
    struct Node** q=(struct Node**)malloc(n*sizeof(struct Node*));
    int front=0,rear=0,i=1;
    struct Node* root=newNode(arr[0]);
    q[rear++]=root;
    while(front<rear&&i<n){
        struct Node* temp=q[front++];
        if(i<n&&arr[i]!=-1){
            temp->left=newNode(arr[i]);
            q[rear++]=temp->left;
        }
        i++;
        if(i<n&&arr[i]!=-1){
            temp->right=newNode(arr[i]);
            q[rear++]=temp->right;
        }
        i++;
    }
    return root;
}

struct Node* lca(struct Node* root,int a,int b){
    if(root==NULL) return NULL;
    if(root->data==a||root->data==b) return root;
    struct Node* left=lca(root->left,a,b);
    struct Node* right=lca(root->right,a,b);
    if(left&&right) return root;
    return left?left:right;
}

int main(){
    int n,i,a,b;
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    scanf("%d%d",&a,&b);
    struct Node* root=buildTree(arr,n);
    struct Node* ans=lca(root,a,b);
    if(ans) printf("%d",ans->data);
    return 0;
}