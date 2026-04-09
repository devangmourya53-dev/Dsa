/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->data=data;
    t->left=t->right=NULL;
    return t;
}

struct Node* buildTree(int arr[],int n){
    if(n==0||arr[0]==-1) return NULL;
    struct Node** q=(struct Node**)malloc(n*sizeof(struct Node*));
    int f=0,r=0,i=1;
    struct Node* root=newNode(arr[0]);
    q[r++]=root;
    while(f<r&&i<n){
        struct Node* cur=q[f++];
        if(i<n&&arr[i]!=-1){
            cur->left=newNode(arr[i]);
            q[r++]=cur->left;
        }
        i++;
        if(i<n&&arr[i]!=-1){
            cur->right=newNode(arr[i]);
            q[r++]=cur->right;
        }
        i++;
    }
    return root;
}

int main(){
    int n,i;
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    struct Node* root=buildTree(arr,n);

    struct Node** q=(struct Node**)malloc(n*sizeof(struct Node*));
    int f=0,r=0;
    int first=1;

    q[r++]=root;

    while(f<r){
        int size=r-f;
        int j;
        for(j=0;j<size;j++){
            struct Node* cur=q[f++];
            if(j==size-1){
                if(!first) printf(" ");
                printf("%d",cur->data);
                first=0;
            }
            if(cur->left) q[r++]=cur->left;
            if(cur->right) q[r++]=cur->right;
        }
    }
    return 0;
}