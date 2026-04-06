/*
Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6 do in c and satisfy the example*/
#include<stdio.h>
#include<stdlib.h>

struct node{int data;struct node*left,*right;};

struct node*newNode(int x){
struct node*n=(struct node*)malloc(sizeof(struct node));
n->data=x;n->left=n->right=NULL;
return n;
}

struct node*build(int a[],int n){
if(n==0||a[0]==-1)return NULL;
struct node**q=(struct node**)malloc(n*sizeof(struct node*));
int f=0,r=0,i=1;
struct node*root=newNode(a[0]);
q[r++]=root;
while(f<r&&i<n){
struct node*cur=q[f++];
if(i<n&&a[i]!=-1){
cur->left=newNode(a[i]);
q[r++]=cur->left;
}
i++;
if(i<n&&a[i]!=-1){
cur->right=newNode(a[i]);
q[r++]=cur->right;
}
i++;
}
free(q);
return root;
}

void inorder(struct node*root){
if(root==NULL)return;
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}

int main(){
int n;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++)scanf("%d",&a[i]);
struct node*root=build(a,n);
inorder(root);
return 0;
}
