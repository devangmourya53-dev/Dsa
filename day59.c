/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/
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

struct Node*build(int in[],int post[],int start,int end,int*idx){
    if(start>end)return NULL;
    struct Node*root=newNode(post[*idx]);
    (*idx)--;
    if(start==end)return root;
    int pos=search(in,start,end,root->data);
    root->right=build(in,post,pos+1,end,idx);
    root->left=build(in,post,start,pos-1,idx);
    return root;
}

void preorder(struct Node*root){
    if(root==NULL)return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int n;
    scanf("%d",&n);
    int in[n],post[n];
    for(int i=0;i<n;i++)scanf("%d",&in[i]);
    for(int i=0;i<n;i++)scanf("%d",&post[i]);
    int idx=n-1;
    struct Node*root=build(in,post,0,n-1,&idx);
    preorder(root);
    return 0;
}