/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/
#include <stdio.h>
#include <stdlib.h>

struct Node{int data;struct Node*left,*right;};

struct Node*newNode(int data){
    struct Node*node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

int search(int in[],int start,int end,int val){
    for(int i=start;i<=end;i++)if(in[i]==val)return i;
    return -1;
}

struct Node*build(int pre[],int in[],int start,int end,int*idx){
    if(start>end)return NULL;
    struct Node*root=newNode(pre[*idx]);
    (*idx)++;
    if(start==end)return root;
    int pos=search(in,start,end,root->data);
    root->left=build(pre,in,start,pos-1,idx);
    root->right=build(pre,in,pos+1,end,idx);
    return root;
}

void postorder(struct Node*root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    int n;
    scanf("%d",&n);
    int pre[n],in[n];
    for(int i=0;i<n;i++)scanf("%d",&pre[i]);
    for(int i=0;i<n;i++)scanf("%d",&in[i]);
    int idx=0;
    struct Node*root=build(pre,in,0,n-1,&idx);
    postorder(root);
    return 0;
}